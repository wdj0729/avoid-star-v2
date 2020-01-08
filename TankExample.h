#pragma once

#include "Game2D.h"
#include <cstdlib>

namespace jm
{
	class MyLine : public Game2D
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(0.0f,-0.9f);
				drawLine(Colors::blue, { -1.5f, 0.0f }, Colors::blue, { 1.5f, 0.0f });
			}
			endTransformation();
		}
	};

	class Mystar : public Game2D
	{
	public:
		float time = 0.0f;
		vec2 center = vec2(0.0f, -0.865f);

		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				translate(0.0f, 0.165f);
				beginTransformation();
				rotate(getRadian(time * 360.0f * 2.0f));
				drawFilledStar(Colors::gold, 0.2f, 0.1f);
				endTransformation();
			}
			endTransformation();

			time += getTimeStep();
		}
	};

	class MyEnemy : public Game2D
	{
	public:
		float time = 0.0f;
		vec2 center = vec2(-1.7f, 0.5f);

		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);
	};

	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f);

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::red, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;

			//화면 벗어날 경우
			if (center.x > 1.4f)
			{
				//bullet의 좌표 초기화
				center.x = -1.4f;

				//속도 상승
				if(velocity.x<0.09f)
					velocity.x = velocity.x + 0.01f;
			}
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyLine line;
		Mystar star;
		//bullet들의 기본 중심값 저장할 객체
		MyEnemy enemy1;
		MyBullet *bullet = nullptr;
		MyBullet *bullet2 = nullptr;
		MyBullet *bullet3 = nullptr;
		MyBullet *bullet4 = nullptr;
		MyBullet *bullet5 = nullptr;
		MyBullet *bullet6 = nullptr;
		MyBullet *bullet7 = nullptr;
		MyBullet *bullet8 = nullptr;
		MyBullet *bullet9 = nullptr;
		MyBullet *bullet10 = nullptr;
		//TODO: allow multiple bullets
		//TODO: delete bullets when they go out of the screen

	public:
		TankExample()
			: Game2D("Avoid Star2", 1024, 768, false, 2)
		{}

		~TankExample()
		{
			if (bullet != nullptr) delete bullet;
			if (bullet2 != nullptr) delete bullet2;
			if (bullet3 != nullptr) delete bullet3;
			if (bullet4 != nullptr) delete bullet4;
			if (bullet5 != nullptr) delete bullet5;
			if (bullet6 != nullptr) delete bullet6;
			if (bullet7 != nullptr) delete bullet7;
			if (bullet8 != nullptr) delete bullet8;
			if (bullet9 != nullptr) delete bullet9;
			if (bullet10 != nullptr) delete bullet10;
		}

		void update()
		{
			// move star

			srand((unsigned int)time(NULL));
			float arr[11];
			//초기 장애물의 x좌표값 랜덤
			for (int i = 0; i <11; i++)
			{
				arr[i] = (rand() % 20 + 1)*0.05f;
			}
			//왼쪽으로 이동
			if (isKeyPressed(GLFW_KEY_LEFT))
			{
				if(star.center.x>=-1.27f)
				star.center.x -= 0.1f * getTimeStep();
			}
			//오른쪽으로 ㅣ동
			if (isKeyPressed(GLFW_KEY_RIGHT))
			{
				if(star.center.x<=1.27f)
				star.center.x += 0.1f * getTimeStep();
			}
			//위로 이동
			if (isKeyPressed(GLFW_KEY_UP))
			{
				if (star.center.y <= 0.6f)
				star.center.y += 0.1f * getTimeStep();
			}
			//아래로 이동
			if (isKeyPressed(GLFW_KEY_DOWN))
			{
				if (star.center.y >= -0.865f)
					star.center.y -= 0.1f * getTimeStep();
			}

			//마우스로 시작
			if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)==true)
			{
				bullet = new MyBullet;
				bullet->center = enemy1.center;
				bullet->center.x += arr[0];
				bullet->center.y += 0.4f;
				bullet->velocity = vec2(0.03f, 0.0f);

				bullet2 = new MyBullet;
				bullet2->center = enemy1.center;
				bullet2->center.x += arr[1];
				bullet2->center.y += 0.25f;
				bullet2->velocity = vec2(0.035f, 0.0f);

				bullet3 = new MyBullet;
				bullet3->center = enemy1.center;
				bullet3->center.x += arr[2];
				bullet3->center.y = 0.05f;
				bullet3->velocity = vec2(0.04f, 0.0f);

				bullet4 = new MyBullet;
				bullet4->center = enemy1.center;
				bullet4->center.x += arr[3];
				bullet4->center.y -= 0.15f;
				bullet4->velocity = vec2(0.025f, 0.0f);

				bullet5 = new MyBullet;
				bullet5->center = enemy1.center;
				bullet5->center.x += arr[4];
				bullet5->center.y -= 0.3f;
				bullet5->velocity = vec2(0.03f, 0.0f);

				bullet6 = new MyBullet;
				bullet6->center = enemy1.center;
				bullet6->center.x += arr[5];
				bullet6->center.y -= 0.5f;
				bullet6->velocity = vec2(0.035f, 0.0f);

				bullet7 = new MyBullet;
				bullet7->center = enemy1.center;
				bullet7->center.x += arr[6];
				bullet7->center.y -= 0.7f;
				bullet7->velocity = vec2(0.04f, 0.0f);

				bullet8 = new MyBullet;
				bullet8->center = enemy1.center;
				bullet8->center.x += arr[7];
				bullet8->center.y -= 0.9f;
				bullet8->velocity = vec2(0.025f, 0.0f);

				bullet9 = new MyBullet;
				bullet9->center = enemy1.center;
				bullet9->center.x += arr[8];
				bullet9->center.y -= 1.1f;
				bullet9->velocity = vec2(0.03f, 0.0f);

				bullet10 = new MyBullet;
				bullet10->center = enemy1.center;
				bullet10->center.x += arr[9];
				bullet10->center.y -= 1.3f;
				bullet10->velocity = vec2(0.035f , 0.0f);
			}

			if (bullet != nullptr) bullet->update(getTimeStep());
			if (bullet2 != nullptr) bullet2->update(getTimeStep());
			if (bullet3 != nullptr) bullet3->update(getTimeStep());
			if (bullet4 != nullptr) bullet4->update(getTimeStep());
			if (bullet5 != nullptr) bullet5->update(getTimeStep());
			if (bullet6 != nullptr) bullet6->update(getTimeStep());
			if (bullet7 != nullptr) bullet7->update(getTimeStep());
			if (bullet8 != nullptr) bullet8->update(getTimeStep());
			if (bullet9 != nullptr) bullet9->update(getTimeStep());
			if (bullet10 != nullptr) bullet10->update(getTimeStep());

			// rendering
			line.draw();
			star.draw();
			if (bullet != nullptr) bullet->draw();
			if (bullet2 != nullptr) bullet2->draw();
			if (bullet3 != nullptr) bullet3->draw();
			if (bullet4 != nullptr) bullet4->draw();
			if (bullet5 != nullptr) bullet5->draw();
			if (bullet6 != nullptr) bullet6->draw();
			if (bullet7 != nullptr) bullet7->draw();
			if (bullet8 != nullptr) bullet8->draw();
			if (bullet9 != nullptr) bullet9->draw();
			if (bullet10 != nullptr) bullet10->draw();
		}
	};
}
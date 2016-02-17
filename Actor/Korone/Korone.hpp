#pragma once
#include <Siv3D.hpp>
# include "../../AMAYADORI/AMAYADORI.hpp"

namespace Korone{

	class Korone : public Player {
	public:
		Korone(Group);
		void Update()override;
		void Attack()override;
		void Draw()const override;
	};

	class NormalBullet : public Bullet {
	public:
		NormalBullet(Group,Vec2,Vec2);
		void Draw()const override;
	};
}
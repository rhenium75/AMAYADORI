#pragma once
# include "../../AMAYADORI/AMAYADORI.hpp"

namespace Flm {

	class Flm : public Actor {
	public:
		Flm();
		void Update()override;
		void Draw()const override;
	};

	class NormalBullet : public Actor {
	public:
		
	};
}
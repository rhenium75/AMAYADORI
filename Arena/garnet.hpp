#pragma once
#include "../AMAYADORI/AMAYADORI.hpp"

namespace Garnet {
	class Garnet : public Player {
		Garnet(Group);
		void Update()override;
		void Draw()const override;
	};
}
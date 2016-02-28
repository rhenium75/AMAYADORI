#pragma once
#include <Siv3D.hpp>
# include "../AMAYADORI/AMAYADORI.hpp"
#define TEAM_None 0
#define TEAM_Player 1
#define TEAM_Enemy 2
#define TEAM_Player1 1
#define TEAM_Player2 4
#define TEAM_Player3 8
#define TEAM_Player4 16
#define FOR(i,l) for(int i = 0;i < l;i++)
#define Look(V1,V2) Atan2((V2.y - V1.y), (V2.x - V1.x))
#define Look(V) Atan2(V.y,V.x)

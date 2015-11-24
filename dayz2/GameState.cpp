#include "GameState.h"

#include "GlobalSystem.h"
#include "lodepng.h"
#include "Console.h"
#include <vector>

CGameState::~CGameState()
{
}

void CGameState::init()
{
	gSys->pPlayer = new CPlayer(0);
	new CPlayer(1);
}

void CGameState::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader.getProgram());
	shader.setMatrix(camera.getCombined());
	gSys->pSpriteRenderer->renderSprites();
	glUseProgram(0);
}

void CGameState::update(float dt)
{
	gSys->pClient->update();
	gSys->pPlayerController->sendInput();

	gSys->pPlayerController->updateMovement();
	gSys->pEntitySystem->update();
	gSys->pConsole->update();

	enet_host_flush(gSys->pClient->client);
}

void CGameState::enter()
{

}

void CGameState::exit()
{

}

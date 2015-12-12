#pragma once

#include "IState.hpp"
#include "../Game/Robot.hpp"

#include <list>

class GameState : public IState
{
public:
	GameState();
	~GameState();

	virtual void enter(sf::RenderTarget*);
	virtual void exit(sf::RenderTarget*);

	virtual void event(const sf::Event&);
	virtual void tick(const Timespan&);
	virtual void update(const Timespan&);
	virtual void draw(sf::RenderTarget&);
	virtual void drawUI(sf::RenderTarget&);

private:
	std::string mCurCommand;
	std::list<std::string> mScripts;

	Timestamp mNextExec;
	Robot mRobot;
};
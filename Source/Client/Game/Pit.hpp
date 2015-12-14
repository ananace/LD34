#pragma once

#include "Entity.hpp"

class Pit : public Entity
{
public:
	Pit();
	~Pit();

	virtual void tick(const Timespan& dt);
	virtual void update(const Timespan& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual bool serialize(char* data, size_t size) const;
	virtual bool deserialize(const char* data, size_t size);

	virtual void initialize();

	virtual const std::string& getName() const;

	void fill();

private:
	bool mFull;
};
#pragma once

#include <Core/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>

class ParticleManager
{
public:
	struct Particle
	{
		Timespan LifeTime;

		sf::Vector2f Size;
		sf::Color StartColor, EndColor;
		sf::Vector2f Gravity;
		float Friction, Rotation;
	};

	static const int MAX_PARTICLES = 256;

	ParticleManager();
	~ParticleManager();

	void addParticle(const Particle& particle, const sf::Vector2f& pos, const sf::Vector2f& dir, float angle);

	void update(const Timespan& dt);
	void draw(sf::RenderTarget& target);

private:
	struct ParticleImpl
	{
		const Particle* Definition;

		Timespan LifeTime;
		sf::Vector2f Position, Velocity;
		float Angle;
	};

	std::vector<ParticleImpl> mParticles;
};
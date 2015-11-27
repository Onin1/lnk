#pragma once

#include <glm\vec2.hpp>

struct IEntity
{
	virtual ~IEntity() {};
	virtual void update() {};
	virtual void init() = 0;
	
	virtual void setPosition(const glm::vec2& pos) { m_pos = pos; }
	virtual const glm::vec2& getPosition() { return m_pos; }
	virtual uint32_t getID() { return m_id; }
	virtual void parsePacket(uint8_t* data, unsigned int length) = 0;
protected:
	glm::vec2 m_pos;
	uint32_t m_id;
};
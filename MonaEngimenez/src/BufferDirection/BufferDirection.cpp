#include "BufferDirection/BufferDirection.h"

BufferDirection::BufferDirection()
{
	this-> start = 0;
	this-> end = 0;
}

BufferDirection::~BufferDirection()
{
}

MONA_ENGIMENEZ int BufferDirection::GetStart()
{
	return start;
}

MONA_ENGIMENEZ int BufferDirection::GetEnd()
{
	return end;
}

MONA_ENGIMENEZ void BufferDirection::SetStart(int newStart)
{
	this->start = newStart;
}

MONA_ENGIMENEZ void BufferDirection::SetEnd(int newEnd)
{
	this->end = newEnd;
}

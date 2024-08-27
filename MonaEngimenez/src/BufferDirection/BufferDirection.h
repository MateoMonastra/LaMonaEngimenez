#pragma once

#include "Exporter.h"
MONA_ENGIMENEZ class BufferDirection
{
private:
	int start;
	int end;
public:
	MONA_ENGIMENEZ BufferDirection() {};
	MONA_ENGIMENEZ ~BufferDirection() {};

	MONA_ENGIMENEZ int GetStart() { return start; }
	MONA_ENGIMENEZ int GetEnd() { return end; }

	MONA_ENGIMENEZ void SetStart(int newStart) { this->start = newStart; }
	MONA_ENGIMENEZ void SetEnd(int newEnd) { this->end = newEnd; }
};
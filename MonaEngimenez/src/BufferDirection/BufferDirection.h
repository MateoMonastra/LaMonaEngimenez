#pragma once
#include "Exporter.h"

MONA_ENGIMENEZ class BufferDirection
{
private:
	int start;
	int end;
public:

	MONA_ENGIMENEZ BufferDirection();
	MONA_ENGIMENEZ ~BufferDirection();

	MONA_ENGIMENEZ int GetStart();
	MONA_ENGIMENEZ int GetEnd();

	MONA_ENGIMENEZ void SetStart(int newStart);
	MONA_ENGIMENEZ void SetEnd(int newEnd);
};
#pragma once

class BufferDirection
{
private:
	int start;
	int end;
public:
	BufferDirection();
	~BufferDirection();

	int GetStart() { return start; }
	int GetEnd() { return end; }

	int SetStart(int newStart) { this->start = newStart; }
	int SetEnd(int newEnd) { this->end = newEnd; }
};
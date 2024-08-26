#pragma once

class BufferDirection
{
private:
	int start;
	int end;
public:
	BufferDirection() {};
	~BufferDirection() {};

	int GetStart() { return start; }
	int GetEnd() { return end; }

	void SetStart(int newStart) { this->start = newStart; }
	void SetEnd(int newEnd) { this->end = newEnd; }
};
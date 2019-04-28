#pragma once

class numbered
{
public:
	numbered(){ mysb = seq++; }
	numbered(const numbered& n){ mysb = seq++; }
	int mysb;
protected:
private:
	static int seq;
};
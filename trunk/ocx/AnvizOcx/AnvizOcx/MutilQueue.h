#pragma once
class CMutilQData
{
private:

public:
	CMutilQData *m_next, *m_prev;
public:
	virtual BOOL EqualOut( CMutilQData* t) = 0;
	virtual CMutilQData *Out() = 0;
	virtual void Clone(CMutilQData *t) = 0;
}
class CMutilQueue
{
private:
	CMutilQData *m_header, *m_end,
	int m_NData;
public:
	CMutilQueue(void);
	~CMutilQueue(void);
	void Out( CMutilQData *pVal);
	void In( CMutilQData *Val);
	void Clear(void);
};

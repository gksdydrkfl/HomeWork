#pragma once

class Monster
{
public:

	void StatusRender();

	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att);

	const char* GetName();

	int GetAtt();

	bool IsDeath();

	int StringCount(const char* _Arr);

private:

	const int LineCount = 40;

	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};
#pragma once


enum CharacterType {
	knight,
	assasin,
	berserk
};


class Character {
	CharacterType type;
	int HP = 1000;
	int armor = 50;
	int addArmor = 40;
	int damage = 100;
	int addDamage = 30;
	double chance = 0.5;
	double addChance = 0.3;
	
	
	bool skillStatus = false; //�������� �� ���������� ������ � ������ ������, ����� �������� 1 ��������� ���
public:
	Character() :type(CharacterType::assasin), HP(1200) {};
	Character(CharacterType Ctype);
	void SetChance(double chance);

	int GetHP();
	int GetArmor();
	int getDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character opponent); //1 - ����� 2 - ������������ ������
private:
	void ResetParams();
	bool CritChance();

};


class Container {
	static const int _SIZE = 10;
	int _size;
	Character Array[_SIZE];
	Container() : _size(0) {};
	Container(int size): _size(size){}

};
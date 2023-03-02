#pragma once


enum CharacterType {
	nobody,
	knight,
	assasin,
	berserk
};


class Character {
	CharacterType _type;
	int _health;
	int _armor;
	int _damage;
	double _chance;
	static const int _ADD_ARMOR = 40,
	_ADD_DAMAGE = 30;
	static constexpr double _ADD_CHANCE = 0.3;
	
	
	bool skillStatus = false; //�������� �� ���������� ������ � ������ ������, ����� �������� 1 ��������� ���
public:
	
	Character() :_type(CharacterType::nobody), _health(0), _damage(0), _armor(0), _chance(0) {};
	Character(CharacterType Ctype);
	void SetChance(double chance);

	int GetHP();
	int GetArmor();
	int GetDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character& opponent); //1 - ����� 2 - ������������ ������
private:
	void _ResetParams();
	bool _CritChance();

};



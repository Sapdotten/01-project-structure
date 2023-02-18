

enum CharacterType {
	knight,
	assasin,
	berserk
};


class Character {
	CharacterType type;
	int HP = 1000;
	int armor = 50;
	int damage = 100;
	double chance = 0.5;
	bool skillStatus = false; //�������� �� ���������� ������ � ������ ������, ����� �������� 1 ��������� ���
public:
	Character(CharacterType Ctype);
	int GetHP();
	int GetArmor();
	int getDamage();
	int Attack();
	int TakeDamage(int Damage);
	void UseSkill();
	int Action(int act, Character opponent); //1 - ������ 2 - ������������ ������
private:
	void ResetParams();

};


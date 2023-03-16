#pragma once
#include <string>

namespace CharacterGame {
	enum CharacterType {
		nobody = 0,
		knight = 1,
		assasin = 2,
		berserk = 3
	};


	class Character {
		CharacterType _type;
		int _health;
		int _armor;
		int _damage;
		double _chance;

		static const int _ADD_ARMOR = 20,
			_ADD_DAMAGE = 20;
		static constexpr double _ADD_CHANCE = 0.3;


		bool skillStatus = false; //�������� �� ���������� ������ � ������ ������, ����� �������� 1 ��������� ���
	public:

		Character() :_type(CharacterType::nobody), _health(0), _damage(0), _armor(0), _chance(0) {};
		Character(CharacterType Ctype);
		void SetChance(double chance);

		CharacterType GetType();
		int GetHP();
		int GetArmor();
		int GetDamage();
		int Damage();
		int TakeDamage(int Damage);
		int Attack(Character& opponent);
		int UseSkill();
	private:
		void _ResetParams();
		bool _CritChance();
		std::string MakeAMove(int choose, Character& opponent);

	};
}


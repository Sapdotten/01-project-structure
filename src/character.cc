#include <character/character.h>
#include <stdexcept>
#include <cstdlib>
#include <ctime>


Character::Character() :_type(CharacterType::nobody), _health(0), _damage(0), _armor(0) {};//����������� �� ��������� ���������� ��� ����� ������
Character::Character(CharacterType Ctype) {
	if (Ctype == nobody)
		throw std::invalid_argument("You can't use this type of character");
	this->_type = Ctype;
	switch (this->_type) {//� ����������� �� ���� ��������� ������������ ������ �������� ��������� ����������
	case knight:
		this->_armor = 70;
		break;
	case assasin:
		this->_health = 1200;
		break;
	case berserk:
		this->_damage = 150;
		break;
	}
}

void Character::SetChance(double chnc) {//������������� ���� ��� ������������ ���������
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (chnc < 0)
		throw std::invalid_argument("Chance can't be negative");
	this->_chance = chnc;
}

int Character::GetHP() {
	return this->_health;
}
int Character::GetArmor() {
	return this->_armor;
}
int Character::GetDamage() {
	return this->_damage;
}

int Character::Attack() {//����������� ����, ������� ������ ������� ����
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (this->_type == berserk && this->_CritChance()) {
			return this->_damage * 3;
	}

	return this->_damage;
}

int Character::TakeDamage(int damage) {//������������ ����,���������� ����������
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (damage < 0)
		throw std::invalid_argument("Damage can't be negative");
	int dmg = 0;
	if (this->_type == knight && this->_CritChance()) {
			dmg = (damage - this->_armor) / 2;
			this->_health = this->_health - dmg;
			return dmg;
	}
	if (this->_type == assasin && this->skillStatus) {
		return 0;
	}
	dmg = damage - this->_armor;
	this->_health = this->_health - dmg;
	return dmg;
}

void Character::UseSkill() {//������ ��������� ��� �����
	if (_type == nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	this->skillStatus = true;
	switch (this->_type) {
	case knight:
		this->_armor += _ADD_ARMOR;
		this->_damage -= _ADD_DAMAGE;
		break;
	case berserk:
		this->_armor -= _ADD_ARMOR;
		this->_chance += addChance;
		this->_damage += _ADD_DAMAGE;
		break;
	}
}

void Character::_ResetParams() {//���������� ��������� ����� ������������� ������
	switch (this->_type) {
	case knight:
		this->_armor -=_ADD_ARMOR;
		this->_damage += _ADD_DAMAGE;
		break;
	case berserk:
		this->_armor += _ADD_ARMOR;
		this->_chance -= addChance;
		this->_damage -= _ADD_DAMAGE;
		break;
	}
	this->skillStatus = false;
}

int Character::Action(int act, Character opponent) {//��������� ������� ���
	if (_type == nobody || opponent._type==nobody)
		throw std::logic_error("You can't use \"nobody\" character");
	if (act != 1 && act != 2)
		throw std::invalid_argument("");
	int dmg = 0;
	switch (act) {
	case 1:
		dmg += opponent.TakeDamage(this->Attack());
		if (this->_type == assasin && this->_CritChance()) {
				dmg += opponent.TakeDamage(this->Attack());
			}
		if (this->skillStatus) {
			if (this->_type == assasin) {
				dmg += opponent.TakeDamage(this->Attack());
			}
			this->_ResetParams();
		}
		return dmg;
	case 2:
		this->UseSkill();
		return -1;
	}


}

bool Character::_CritChance() {//����������� ���� ��������� �����
	srand(time(0));
	int inChance = 1 + rand() % 100;
	if (inChance <= this->_chance * 100) {
		return true;
	}
	return false;
}

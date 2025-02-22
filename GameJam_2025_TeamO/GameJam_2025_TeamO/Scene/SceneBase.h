#pragma once

#include"../Objects/GameObjectBase.h"
#include <vector>
#include <string>

/// <summary>
/// �V�[�����N���X
/// </summary>
class SceneBase
{
protected:
	// �e�V�[�������L������
	std::vector<GameObjectBase*>	create_list;	// �������s���I�u�W�F�N�g���X�g
	std::vector<GameObjectBase*>	object_list;	// �X�V�ƕ`����s���I�u�W�F�N�g���X�g
	std::vector<GameObjectBase*>	destroy_list;	// �j�����s���I�u�W�F�N�g���X�g
	Vector2D						screen_offset;	// �X�N���[���I�t�Z�b�g

public:
	SceneBase() :
		create_list(),
		object_list(),
		destroy_list(),
		screen_offset(0.0f)
	{

	}
	virtual ~SceneBase()
	{
		// ����Y��h�~
		Finalize();
	}

public:
	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize()
	{
	}

	
	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() const
	{
		// �I�u�W�F�N�g���X�g���̃I�u�W�F�N�g��`�悷��
		for (GameObjectBase* obj : object_list)
		{
			obj->Draw(screen_offset);
		}
	}

	/// <summary>
	/// �I��������
	/// </summary>
	virtual void Finalize()
	{
		// �I�u�W�F�N�g���X�g���̃I�u�W�F�N�g��j������
		DestoryAllObject();

		// ���I�z��̉��
		if (!create_list.empty())
		{
			create_list.clear();
		}
		if (!destroy_list.empty())
		{
			destroy_list.clear();
		}
	}


public:
	/// <summary>
	/// �Q�[���I�u�W�F�N�g��������
	/// </summary>
	/// <typeparam name="OBJECT">��������Q�[���I�u�W�F�N�g�N���X</typeparam>
	/// <param name="generate_location">�����ʒu</param>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^</returns>
	template <class OBJECT>
	OBJECT* CreateObject(const Vector2D& generate_location)
	{
		// ��������Q�[���I�u�W�F�N�g�N���X�𓮓I�m��
		OBJECT* new_instance = new OBJECT();
		// GameObjectBase���p�����Ă��邩�m�F
		GameObjectBase* new_object = dynamic_cast<GameObjectBase*>(new_instance);
		// �G���[�`�F�b�N
		if (new_object == nullptr)
		{
			// ���I�m�ۂ����������̊J��
			delete new_instance;
			// ��O�e�L�X�g��ʒm
			throw std::string("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
			return nullptr;
		}
		// �V�[�����̐ݒ�
		new_object->SetOwnerScene(this);
		// �I�u�W�F�N�g�̏�����
		new_object->Initialize();
		// �ʒu���̐ݒ�
		new_object->SetLocation(generate_location);
		// �����I�u�W�F�N�g���X�g�̖����Ɋi�[����
		create_list.push_back(new_object);
		// ���������Q�[���I�u�W�F�N�g�̃|�C���^��Ԃ�
		return new_instance;
	}

	/// <summary>
	/// �I�u�W�F�N�g�j������
	/// </summary>
	/// <param name="target">�j�����s���Q�[���I�u�W�F�N�g�̃|�C���^</param>
	void DestroyObject(GameObjectBase* target)
	{
		// �k���|�`�F�b�N
		if (target == nullptr)
		{
			return;
		}

		// �j���I�u�W�F�N�g���X�g���ɂ���΁A�ǉ����Ȃ�
		for (GameObjectBase* obj : destroy_list)
		{
			if (obj == target)
			{
				return;
			}
		}

		// �j�����s���I�u�W�F�N�g���X�g�ɒǉ�����
		destroy_list.push_back(target);
	}

	/// <summary>
	/// �X�N���[���I�t�Z�b�g���擾����
	/// </summary>
	/// <returns>�X�N���[���I�t�Z�b�g�l</returns>
	const Vector2D GetScreenOffset() const
	{
		return screen_offset;
	}

private:
	/// <summary>
	/// �V�[�����I�u�W�F�N�g�j������
	/// </summary>
	void DestoryAllObject()
	{
		// �I�u�W�F�N�g���X�g����Ȃ珈�����I������
		if (object_list.empty())
		{
			return;
		}
		// �I�u�W�F�N�g���X�g���̃I�u�W�F�N�g���폜����
		for (GameObjectBase* obj : object_list)
		{
			obj->Finalize();
			delete obj;
		}
		// ���I�z��̉��
		object_list.clear();
	}
};

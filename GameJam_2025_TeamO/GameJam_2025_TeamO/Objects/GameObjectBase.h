#pragma once

#include "../Utility/Vector2D.h"

#define D_OBJECT_SIZE	(24.0f)			// �ǂ̃T�C�Y


// �Q�[���I�u�W�F�N�g���N���X
class GameObjectBase
{
protected:
	class SceneBase* owner_scene;	// ���L����V�[�����
	Vector2D			location;		// �ʒu���W
	Vector2D			size;			// �T�C�Y
	int					image;			// �摜���
	int					z_layer;		// ���C���[���
	Vector2D            velocity;       //�ړ���
	bool flip_flag;     //���]�O���t

public:
	GameObjectBase();
	virtual ~GameObjectBase();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	virtual void Update(float delta_second);
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="screen_offset">�I�t�Z�b�g�l</param>
	virtual void Draw(const Vector2D& screen_offset) const;
	/// <summary>
	/// �I��������
	/// </summary>
	virtual void Finalize();

public:
	/// <summary>
	/// �����蔻��ʒm����
	/// </summary>
	/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
	virtual void OnHitCollision(GameObjectBase* hit_object);

public:
	/// <summary>
	/// ���L�V�[�����̐ݒ�
	/// </summary>
	/// <param name="scene">���L�V�[�����</param>
	void SetOwnerScene(class SceneBase* scene);

	/// <summary>
	/// �ʒu���W�擾����
	/// </summary>
	/// <returns>�ʒu���W���</returns>
	const Vector2D& GetLocation() const;

	/// <summary>
	/// �T�C�Y�擾����
	/// </summary>
	/// <returns>�T�C�Y���</returns>
	const Vector2D& GetSize() const;

	/// <summary>
	/// �ʒu���ύX����
	/// </summary>
	/// <param name="location">�ύX�������ʒu���</param>
	void SetLocation(const Vector2D& location);

	/// <summary>
	/// �y���C���[���擾����
	/// </summary>
	/// <returns>�y���C���[���</returns>
	const int GetZLayer() const;
};

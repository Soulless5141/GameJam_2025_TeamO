#pragma once

#include "../Utility/Vector2D.h"

#define D_OBJECT_SIZE	(24.0f)			// 壁のサイズ


// ゲームオブジェクト基底クラス
class GameObjectBase
{
protected:
	class SceneBase* owner_scene;	// 所有するシーン情報
	Vector2D			location;		// 位置座標
	Vector2D			size;			// サイズ
	int					image;			// 画像情報
	int					z_layer;		// レイヤー情報
	Vector2D            velocity;       //移動量
	bool flip_flag;     //反転グラフ

public:
	GameObjectBase();
	virtual ~GameObjectBase();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	virtual void Update(float delta_second);
	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="screen_offset">オフセット値</param>
	virtual void Draw(const Vector2D& screen_offset) const;
	/// <summary>
	/// 終了時処理
	/// </summary>
	virtual void Finalize();

public:
	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	virtual void OnHitCollision(GameObjectBase* hit_object);

public:
	/// <summary>
	/// 所有シーン情報の設定
	/// </summary>
	/// <param name="scene">所有シーン情報</param>
	void SetOwnerScene(class SceneBase* scene);

	/// <summary>
	/// 位置座標取得処理
	/// </summary>
	/// <returns>位置座標情報</returns>
	const Vector2D& GetLocation() const;

	/// <summary>
	/// サイズ取得処理
	/// </summary>
	/// <returns>サイズ情報</returns>
	const Vector2D& GetSize() const;

	/// <summary>
	/// 位置情報変更処理
	/// </summary>
	/// <param name="location">変更したい位置情報</param>
	void SetLocation(const Vector2D& location);

	/// <summary>
	/// Ｚレイヤー情報取得処理
	/// </summary>
	/// <returns>Ｚレイヤー情報</returns>
	const int GetZLayer() const;
};

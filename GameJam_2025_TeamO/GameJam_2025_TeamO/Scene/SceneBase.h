#pragma once

#include"../Objects/GameObjectBase.h"
#include <vector>
#include <string>

/// <summary>
/// シーン基底クラス
/// </summary>
class SceneBase
{
protected:
	// 各シーンが所有する情報
	std::vector<GameObjectBase*>	create_list;	// 生成を行うオブジェクトリスト
	std::vector<GameObjectBase*>	object_list;	// 更新と描画を行うオブジェクトリスト
	std::vector<GameObjectBase*>	destroy_list;	// 破棄を行うオブジェクトリスト
	Vector2D						screen_offset;	// スクリーンオフセット

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
		// 解放忘れ防止
		Finalize();
	}

public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize()
	{
	}

	
	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() const
	{
		// オブジェクトリスト内のオブジェクトを描画する
		for (GameObjectBase* obj : object_list)
		{
			obj->Draw(screen_offset);
		}
	}

	/// <summary>
	/// 終了時処理
	/// </summary>
	virtual void Finalize()
	{
		// オブジェクトリスト内のオブジェクトを破棄する
		DestoryAllObject();

		// 動的配列の解放
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
	/// ゲームオブジェクト生成処理
	/// </summary>
	/// <typeparam name="OBJECT">生成するゲームオブジェクトクラス</typeparam>
	/// <param name="generate_location">生成位置</param>
	/// <returns>生成したゲームオブジェクトのポインタ</returns>
	template <class OBJECT>
	OBJECT* CreateObject(const Vector2D& generate_location)
	{
		// 生成するゲームオブジェクトクラスを動的確保
		OBJECT* new_instance = new OBJECT();
		// GameObjectBaseを継承しているか確認
		GameObjectBase* new_object = dynamic_cast<GameObjectBase*>(new_instance);
		// エラーチェック
		if (new_object == nullptr)
		{
			// 動的確保したメモリの開放
			delete new_instance;
			// 例外テキストを通知
			throw std::string("ゲームオブジェクトが生成できませんでした");
			return nullptr;
		}
		// シーン情報の設定
		new_object->SetOwnerScene(this);
		// オブジェクトの初期化
		new_object->Initialize();
		// 位置情報の設定
		new_object->SetLocation(generate_location);
		// 生成オブジェクトリストの末尾に格納する
		create_list.push_back(new_object);
		// 生成したゲームオブジェクトのポインタを返す
		return new_instance;
	}

	/// <summary>
	/// オブジェクト破棄処理
	/// </summary>
	/// <param name="target">破棄を行うゲームオブジェクトのポインタ</param>
	void DestroyObject(GameObjectBase* target)
	{
		// ヌルポチェック
		if (target == nullptr)
		{
			return;
		}

		// 破棄オブジェクトリスト内にあれば、追加しない
		for (GameObjectBase* obj : destroy_list)
		{
			if (obj == target)
			{
				return;
			}
		}

		// 破棄を行うオブジェクトリストに追加する
		destroy_list.push_back(target);
	}

	/// <summary>
	/// スクリーンオフセット情報取得処理
	/// </summary>
	/// <returns>スクリーンオフセット値</returns>
	const Vector2D GetScreenOffset() const
	{
		return screen_offset;
	}

private:
	/// <summary>
	/// シーン内オブジェクト破棄処理
	/// </summary>
	void DestoryAllObject()
	{
		// オブジェクトリストが空なら処理を終了する
		if (object_list.empty())
		{
			return;
		}
		// オブジェクトリスト内のオブジェクトを削除する
		for (GameObjectBase* obj : object_list)
		{
			obj->Finalize();
			delete obj;
		}
		// 動的配列の解放
		object_list.clear();
	}
};

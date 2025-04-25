#pragma once
#include <includes.h>

class ESP : public FeatureFactory
{
protected:
	float fColor[4] = { 1.0, 1.0, 1.0, 1.0 };
private:
	Distance espDistance;

public:
	void Draw();
	void Render();
	void Run();
};

//struct ESPObject {
//	
//	enum class Box {
//		Box2D,
//		Box3D,
//		Box2DOutlined,
//		Box3DOutlined,
//		MAX
//	};
//
//	enum class CorneredBox {
//		Corner2D,
//		Corner3D,
//		Corner2DOutlined,
//		Corner3DOutlined,
//		MAX
//	};
//
//	struct Tracer {
//		float color[4];
//		float outline_color[4];
//
//		Tracer(float color[4], float outline_color[4]) :
//			color(color[4]),
//			outline_color(outline_color[4])
//			{};
//
//	};
//};


//class IESPObject
//{
//public:
//	virtual bool IsInScreenView() = 0;
//	virtual bool SetIsInScreenView() = 0;
//
//	virtual void Render() = 0;
//};
//
//class ESPObjectBase : public IESPObject
//{
//private:
//	bool m_bAtScreen{ false };
//
//protected:
//	bool bShouldRender{ true };
//
//public:
//	void Render();
//	ESPObjectBase Get();
//	bool IsInScreenView();
//	bool SetIsInScreenView(const bool &AtScreen);
//};
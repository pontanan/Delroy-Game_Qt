#include <QWidget>

class GameObject
{
public:
	GameObject();
	virtual void paint(QPainter * qp) = 0;
	virtual ~GameObject();
};


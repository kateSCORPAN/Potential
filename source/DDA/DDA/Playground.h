#pragma once
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QGraphicsScene.h>
#include <QGraphicsView.h>
#include <QGraphicsItem>
#include <vector>

#include "Agent.h"
#include "Obstacle.h"

using namespace std;

class Playground :
	public QWidget
{
Q_OBJECT

private :
	QTimer * timer;
	QGraphicsScene scene;
	QGraphicsItem * item;

	int numberAgents;
	int numberObstacles;
	vector<Agent *> agent;
	vector<Obstacle *> obstacle;
	QTime time;

	qreal fieldCenterX;
	qreal fieldCenterY;
	float ** potentialField;
public:
	Playground(QWidget *parent = 0);
	~Playground(void);
	void SetEnvironment();
	void ClearEnvironment();
	void CountPotentialField(int agentID);
	float CountPotentialFieldTile(int agentID, int x, int y);
public slots:
	void Tick();
};


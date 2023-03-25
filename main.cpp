#include "Graph.h"

auto main() -> int
{
	system("chcp 1251");
	system("cls");

	Graph socialConnections;

	socialConnections.addVertex(0, "���������");
	socialConnections.addVertex(1, "������");
	socialConnections.addVertex(2, "���������");
	socialConnections.addVertex(3, "��������");
	socialConnections.addVertex(4, "�����");
	socialConnections.addVertex(5, "���������");
	socialConnections.addVertex(6, "�����");
	socialConnections.addVertex(7, "�������");
	socialConnections.addVertex(8, "������");
	socialConnections.addVertex(9, "����");
	socialConnections.addVertex(10, "�������");
	socialConnections.addVertex(11, "Ը���");
	socialConnections.addVertex(12, "�������");
	socialConnections.addVertex(13, "��������");
	socialConnections.addVertex(14, "������");

	socialConnections.addEdge(0, 1);
	socialConnections.addEdge(0, 3);
	socialConnections.addEdge(0, 4);
	socialConnections.addEdge(1, 2);
	socialConnections.addEdge(1, 3);
	socialConnections.addEdge(1, 4);
	socialConnections.addEdge(2, 4);
	socialConnections.addEdge(2, 11);
	socialConnections.addEdge(3, 6);
	socialConnections.addEdge(4, 6);
	socialConnections.addEdge(4, 8);
	socialConnections.addEdge(5, 7);
	socialConnections.addEdge(5, 11);
	socialConnections.addEdge(6, 9);
	socialConnections.addEdge(7, 9);
	socialConnections.addEdge(8, 11);
	socialConnections.addEdge(9, 13);
	socialConnections.addEdge(10, 12);
	socialConnections.addEdge(11, 13);
	socialConnections.addEdge(11, 14);
	socialConnections.addEdge(12, 13);

	socialConnections.findMinDistancesFloyd();
	socialConnections.printSocialConnections();

	return 0;
}
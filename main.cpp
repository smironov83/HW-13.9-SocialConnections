#include "Graph.h"

auto main() -> int
{
	system("chcp 1251");
	system("cls");

	Graph socialConnections;

	socialConnections.addVertex(0, "Екатерина");
	socialConnections.addVertex(1, "Сергей");
	socialConnections.addVertex(2, "Мирослава");
	socialConnections.addVertex(3, "Виктория");
	socialConnections.addVertex(4, "Елена");
	socialConnections.addVertex(5, "Александр");
	socialConnections.addVertex(6, "Ольга");
	socialConnections.addVertex(7, "Дмитрий");
	socialConnections.addVertex(8, "Никита");
	socialConnections.addVertex(9, "Иван");
	socialConnections.addVertex(10, "Василий");
	socialConnections.addVertex(11, "Фёдор");
	socialConnections.addVertex(12, "Надежда");
	socialConnections.addVertex(13, "Светлана");
	socialConnections.addVertex(14, "Максим");

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
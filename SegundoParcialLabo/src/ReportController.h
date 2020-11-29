/*
 * ReportController.h
 *
 *  Created on: 25 nov. 2020
 *      Author: totinho91
 */

#ifndef REPORTCONTROLLER_H_
#define REPORTCONTROLLER_H_

int IsClientId(void* pElement, int id);
int GetVentasPorClientId(void* pElement, int id);
int controller_saveSaleReportAsText(char* path , LinkedList* pArrayListClient, LinkedList* pArrayListSale);
int controller_PrintClienstWithMoreAndLessSales(LinkedList* pArrayListClient, LinkedList* pArrayListSale);
int controller_PrintSaleWithMorePosters(LinkedList* pArrayListClient, LinkedList* pArrayListSale);

#endif /* REPORTCONTROLLER_H_ */

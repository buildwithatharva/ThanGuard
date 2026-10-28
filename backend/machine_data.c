#include <stdio.h>
#include <string.h>
#include "machine_data.h"

int load_sample_components(Component c[], int capacity) {
 const char *names[MAX_COMPONENTS] = {
  "Motor 1","Joint 1","Shaft 1","Gear 1","Bearing 1",
  "Motor 2","Joint 2","Shaft 2","Gear 2","Bearing 2",
  "Motor 3","Joint 3","Shaft 3","Gear 3","Bearing 3",
  "Motor 4","Joint 4","Shaft 4","Gear 4","Bearing 4",
  "Motor 5","Joint 5","Shaft 5","Gear 5","Bearing 5"
 };
 int i, n = capacity < MAX_COMPONENTS ? capacity : MAX_COMPONENTS;
 for (i=0;i<n;i++) {
  c[i].id=i+1; snprintf(c[i].name,sizeof(c[i].name),"%s",names[i]);
  c[i].temperature=45.0; c[i].vibration=2.0; c[i].riskScore=RISK_NOT_ANALYZED;
 }
 /* Demonstration values: one warning and one critical component. */
 if(n>IDX_MOTOR_2){c[IDX_MOTOR_2].temperature=82.0;c[IDX_MOTOR_2].vibration=6.5;}
 if(n>IDX_BEARING_4){c[IDX_BEARING_4].temperature=96.0;c[IDX_BEARING_4].vibration=8.0;}
 return n;
}
int find_component_index_by_id(const Component c[], int count, int id) {
 int i; for(i=0;i<count;i++) if(c[i].id==id) return i; return -1;
}
void print_component_table(const Component c[], int count) {
 int i;
 printf("\nID  Component       Temp(C)  Vibration  Risk\n");
 printf("----------------------------------------------\n");
 for(i=0;i<count;i++) {
  const char *risk=c[i].riskScore==RISK_NOT_ANALYZED?"Not analyzed":
   c[i].riskScore>=70?"CRITICAL":c[i].riskScore>=40?"WARNING":"NORMAL";
  printf("%-3d %-15s %-8.1f %-10.1f %s\n",c[i].id,c[i].name,c[i].temperature,c[i].vibration,risk);
 }
}
void assess_risk(Component c[], int count) {
 int i;
 for(i=0;i<count;i++) {
  int score=0;
  if(c[i].temperature>=90) score+=50; else if(c[i].temperature>=75) score+=25;
  if(c[i].vibration>=7) score+=50; else if(c[i].vibration>=5) score+=25;
  if(score>100) score=100;
  c[i].riskScore=score;
 }
}

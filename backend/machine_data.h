#ifndef MACHINE_DATA_H
#define MACHINE_DATA_H
#define MAX_COMPONENTS 25
#define RISK_NOT_ANALYZED -1
typedef enum {
 IDX_MOTOR_1=0, IDX_JOINT_1, IDX_SHAFT_1, IDX_GEAR_1, IDX_BEARING_1,
 IDX_MOTOR_2, IDX_JOINT_2, IDX_SHAFT_2, IDX_GEAR_2, IDX_BEARING_2,
 IDX_MOTOR_3, IDX_JOINT_3, IDX_SHAFT_3, IDX_GEAR_3, IDX_BEARING_3,
 IDX_MOTOR_4, IDX_JOINT_4, IDX_SHAFT_4, IDX_GEAR_4, IDX_BEARING_4,
 IDX_MOTOR_5, IDX_JOINT_5, IDX_SHAFT_5, IDX_GEAR_5, IDX_BEARING_5
} ComponentIndex;
typedef struct {
 int id;
 char name[32];
 double temperature;
 double vibration;
 int riskScore;
} Component;
int load_sample_components(Component components[], int capacity);
int find_component_index_by_id(const Component components[], int count, int id);
void print_component_table(const Component components[], int count);
void assess_risk(Component components[], int count);
#endif

#include <stdio.h>
#include <string.h>
void main()
{
    typedef struct emp{
        int empid;
        char empname[15];
    }empdata_t;
    empdata_t cdac_hyd[3];
    empdata_t cdac_pune[5];
    for (int i=0;i<3;i++)
    {
        cdac_hyd[i].empid = i+1;
        scanf("%s",&cdac_hyd[i].empname);
    }
    for (int i=0;i<5;i++)
    {
        cdac_pune[i].empid = i+1;
        scanf("%s",&cdac_pune[i].empname);
    }
    printf("\nPUNE details");
    for (int i=0;i<5;i++)
    {
        printf("\nEmp name=%s",cdac_pune[i].empname);
        printf("\nEmpid= %d\n\n",cdac_pune[i].empid);
    }
    printf("\nHYD details");
    for (int i=0;i<3;i++)
    {
        printf("\nEmp name=%s",cdac_hyd[i].empname);
        printf("\nEmpid= %d\n\n",cdac_hyd[i].empid);
    }


}

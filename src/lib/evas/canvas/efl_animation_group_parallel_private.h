#define EFL_ANIMATION_PROTECTED

#include "evas_common_private.h"
#include <Ecore.h>

#define MY_CLASS EFL_ANIMATION_GROUP_PARALLEL_CLASS
#define MY_CLASS_NAME efl_class_name_get(MY_CLASS)

#define EFL_ANIMATION_GROUP_PARALLEL_DATA_GET(o, pd) \
   Efl_Animation_Group_Parallel_Data *pd = efl_data_scope_get(o, EFL_ANIMATION_GROUP_PARALLEL_CLASS)

typedef struct _Efl_Animation_Group_Parallel_Data
{
} Efl_Animation_Group_Parallel_Data;

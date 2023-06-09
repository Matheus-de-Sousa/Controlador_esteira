#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "SharedStruct.hpp"
#include "TaskEspNow.hpp"
#include "TaskIHM.hpp"

#include "esp_log.h"

TaskEspNow *EspNowProtocol;
TaskIHM *LCDInterface; 
SharedStruct sharedData;
extern "C"
{
  void app_main(void);
}

void app_main() 
{
    sharedData.xSemaphore = xSemaphoreCreateMutex();
    esp_log_level_set("*", ESP_LOG_ERROR);
    esp_log_level_set("main", ESP_LOG_ERROR);
    LCDInterface = new TaskIHM("TaskIHM",4096,3, &sharedData);
    EspNowProtocol = TaskEspNow::getInstance("TaskEspNow",4096,4, &sharedData);
    LCDInterface->Start();
    for(;;)
    {
        ESP_LOGI("main", "TaskEspNow: %d", eTaskGetState(EspNowProtocol->GetHandle()));
        ESP_LOGI("main", "TaskIHM: %d", eTaskGetState(LCDInterface->GetHandle()));
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
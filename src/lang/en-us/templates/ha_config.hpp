#pragma once
#include <Arduino.h>

#include "templates/partials.hpp"

namespace templates {

const char configTemplate[] PROGMEM = R"====(
{
  "name": "{{name}}",
  "unique_id": "{{unique_id}}",
  "modes": [
    "heat_cool",
    "cool",
    "dry",
    {{#supportHeatMode}}
    "heat",
    {{/supportHeatMode}}
    "fan_only",
    "off"
  ],
  "mode_cmd_t": "{{mode_cmd_t}}",
  "mode_stat_t": "{{mode_stat_t}}",
  "mode_stat_tpl": "{{>lbrace}}{{>lbrace}} value_json.mode if (value_json is defined and value_json.mode is defined and value_json.mode|length) else 'off' {{>rbraces}}",
  "temp_cmd_t": "{{temp_cmd_t}}",
  "temp_stat_t": "{{temp_stat_t}}",
  "avty_t": "{{avty_t}}",
  "pl_not_avail": "offline",
  "pl_avail": "online",
  "temp_stat_tpl": "{{#tempStatTpl}}{% if (value_json is defined and value_json.{{fieldName}} is defined) %}{% if (value_json.{{fieldName}}|int >= {{minTemp}} and value_json.temperature|int <= {{maxTemp}}) %}{{>lbrace}}{{>lbrace}} value_json.{{fieldName}} {{>rbraces}}{% elif (value_json.{{fieldName}}|int < {{minTemp}}) %}{{minTemp}}{% elif (value_json.{{fieldName}}|int > {{maxTemp}}) %}{{maxTemp}}{% endif %}{% else %}{{defaultTemp}}{% endif %}{{/tempStatTpl}}",
  "curr_temp_t": "{{curr_temp_t}}",
  "curr_temp_tpl": "{{#currTempTpl}}{{>lbrace}}{{>lbrace}} value_json.{{fieldName}} if (value_json is defined and value_json.{{fieldName}} is defined and value_json.{{fieldName}}|int > {{minTemp}}) {{>rbraces}}{{/currTempTpl}}",
  "min_temp": {{min_temp}},
  "max_temp": {{max_temp}},
  "temp_step": "1",
  "temperature_unit": "F",
  "fan_modes": [
    "AUTO",
    "QUIET",
    "1",
    "2",
    "3",
    "4"
  ],
  "fan_mode_cmd_t": "{{fan_mode_cmd_t}}",
  "fan_mode_stat_t": "{{fan_mode_stat_t}}",
  "fan_mode_stat_tpl": "{{>lbrace}}{{>lbrace}} value_json.fan if (value_json is defined and value_json.fan is defined and value_json.fan|length) else 'AUTO' {{>rbraces}}",
  "swing_modes": [
    "AUTO",
    "1",
    "2",
    "3",
    "4",
    "5",
    "SWING"
  ],
  "swing_mode_cmd_t": "{{swing_mode_cmd_t}}",
  "swing_mode_stat_t": "{{swing_mode_stat_t}}",
  "swing_mode_stat_tpl": "{{>lbrace}}{{>lbrace}} value_json.vane if (value_json is defined and value_json.vane is defined and value_json.vane|length) else 'AUTO' {{>rbraces}}",
  "action_topic": "{{action_topic}}",
  "action_template": "{{>lbrace}}{{>lbrace}} value_json.action if (value_json is defined and value_json.action is defined and value_json.action|length) else 'idle' {{>rbraces}}",
  "device": { 
    "ids": "{{friendlyName}}",
    "name": "{{friendlyName}}",
    "sw": "Mitsubishi2MQTT {{buildDate}} ({{commitHash}})",
    "mdl": "HVAC MITSUBISHI",
    "mf": "MITSUBISHI ELECTRIC",
    "configuration_url": "http://{{localIP}}"
  },
  "json_attr_t": "{{json_attr_t}}",
  "json_attr_tpl": "{{>lbrace}}{{>lbrace}} {'compressorFrequency': value_json.compressorFrequency if (value_json is defined and value_json.compressorFrequency is defined) else '-1' } | tojson {{>rbraces}}"
}
)====";
};  // namespace templates
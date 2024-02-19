#pragma once
#include <Arduino.h>

namespace views {

const char* autoConfigTemplate PROGMEM = R"====(
{{=<% %>=}}
{
  "name": "<% name %>",
  "unique_id": "<% unique_id %>",
  "modes": [
    "heat_cool",
    "cool",
    "dry",
    <%#supportHeatMode%>
    "heat",
    <%/supportHeatMode%>
    "fan_only",
    "off"
  ],
  "mode_cmd_t": "<% mode_cmd_t %>",
  "mode_stat_t": "<% mode_stat_t %>",
  "mode_stat_tpl": "{{ value_json.mode if (value_json is defined and value_json.mode is defined and value_json.mode|length) else 'off' }}",
  "temp_cmd_t": "<% temp_cmd_t %>",
  "temp_stat_t": "<% temp_stat_t %>",
  "avty_t": "<% avty_t %>",
  "pl_not_avail": "offline",
  "pl_avail": "online",
  "temp_stat_tpl": "<%#tempStatTpl%>{% if (value_json is defined and value_json.<% fieldName %> is defined) %}{% if (value_json.<% fieldName %>|int >= <% minTemp %> and value_json.temperature|int <= <% maxTemp %>) %}{{ value_json.<% fieldName %> }}{% elif (value_json.<% fieldName %>|int < <% minTemp %>) %}<% minTemp %>{% elif (value_json.<% fieldName %>|int > <% maxTemp %>) %}<% maxTemp %>{% endif %}{% else %}<% defaultTemp %>{% endif %}<%/tempStatTpl%>",
  "curr_temp_t": "<% curr_temp_t %>",
  "curr_temp_tpl": "<%#currTempTpl%>{{ value_json.<% fieldName %> if (value_json is defined and value_json.<% fieldName %> is defined and value_json.<% fieldName %>|int > <% minTemp %>) }}<%/currTempTpl%>",
  "min_temp": <% min_temp %>,
  "max_temp": <% max_temp %>,
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
  "fan_mode_cmd_t": "<% fan_mode_cmd_t %>",
  "fan_mode_stat_t": "<% fan_mode_stat_t %>",
  "fan_mode_stat_tpl": "{{ value_json.fan if (value_json is defined and value_json.fan is defined and value_json.fan|length) else 'AUTO' }}",
  "swing_modes": [
    "AUTO",
    "1",
    "2",
    "3",
    "4",
    "5",
    "SWING"
  ],
  "swing_mode_cmd_t": "<% swing_mode_cmd_t %>",
  "swing_mode_stat_t": "<% swing_mode_stat_t %>",
  "swing_mode_stat_tpl": "{{ value_json.vane if (value_json is defined and value_json.vane is defined and value_json.vane|length) else 'AUTO' }}",
  "action_topic": "<% action_topic %>",
  "action_template": "{{ value_json.action if (value_json is defined and value_json.action is defined and value_json.action|length) else 'idle' }}",
  "device": { 
    "ids": "<% friendlyName %>",
    "name": "<% friendlyName %>",
    "sw": "Mitsubishi2MQTT <% buildDate %> (<% commitHash %>)",
    "mdl": "HVAC MITSUBISHI",
    "mf": "MITSUBISHI ELECTRIC",
    "configuration_url": "http://<% localIP %>"
  },
  "json_attr_t": "<% json_attr_t %>",
  "json_attr_tpl": "{{ {'compressorFrequency': value_json.compressorFrequency if (value_json is defined and value_json.compressorFrequency is defined) else '-1' } | tojson }}"
}
)====";
};  // namespace views

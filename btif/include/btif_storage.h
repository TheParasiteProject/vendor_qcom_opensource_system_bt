/******************************************************************************
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#ifndef BTIF_STORAGE_H
#define BTIF_STORAGE_H

#include <hardware/bluetooth.h>

#include "bt_target.h"
#include "bt_types.h"

/*******************************************************************************
 *  Constants & Macros
 *******************************************************************************/
#define BTIF_STORAGE_FILL_PROPERTY(p_prop, t, l, p_v) \
  do {                                                \
    (p_prop)->type = (t);                             \
    (p_prop)->len = (l);                              \
    (p_prop)->val = (p_v);                            \
  } while (0)

/*******************************************************************************
 *  Functions
 *******************************************************************************/

/*******************************************************************************
 *
 * Function         btif_storage_get_adapter_property
 *
 * Description      BTIF storage API - Fetches the adapter property->type
 *                  from NVRAM and fills property->val.
 *                  Caller should provide memory for property->val and
 *                  set the property->val
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_adapter_property(bt_property_t* property);

/*******************************************************************************
 *
 * Function         btif_storage_set_adapter_property
 *
 * Description      BTIF storage API - Stores the adapter property
 *                  to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_set_adapter_property(bt_property_t* property);

/*******************************************************************************
 *
 * Function         btif_storage_get_remote_device_property
 *
 * Description      BTIF storage API - Fetches the remote device property->type
 *                  from NVRAM and fills property->val.
 *                  Caller should provide memory for property->val and
 *                  set the property->val
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_remote_device_property(bt_bdaddr_t* remote_bd_addr,
                                                    bt_property_t* property);

/*******************************************************************************
 *
 * Function         btif_storage_set_remote_device_property
 *
 * Description      BTIF storage API - Stores the remote device property
 *                  to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_set_remote_device_property(bt_bdaddr_t* remote_bd_addr,
                                                    bt_property_t* property);

/*******************************************************************************
 *
 * Function         btif_storage_add_remote_device
 *
 * Description      BTIF storage API - Adds a newly discovered device to
 *                  track along with the timestamp. Also, stores the various
 *                  properties - RSSI, BDADDR, NAME (if found in EIR)
 *
 * Returns          BT_STATUS_SUCCESS if successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_add_remote_device(bt_bdaddr_t* remote_bd_addr,
                                           uint32_t num_properties,
                                           bt_property_t* properties);

/*******************************************************************************
 *
 * Function         btif_storage_add_bonded_device
 *
 * Description      BTIF storage API - Adds the newly bonded device to NVRAM
 *                  along with the link-key, Key type and Pin key length
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_add_bonded_device(bt_bdaddr_t* remote_bd_addr,
                                           LINK_KEY link_key, uint8_t key_type,
                                           uint8_t pin_length);

/*******************************************************************************
 *
 * Function         btif_storage_remove_bonded_device
 *
 * Description      BTIF storage API - Deletes the bonded device from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_bonded_device(bt_bdaddr_t* remote_bd_addr);

/*******************************************************************************
 *
 * Function         btif_storage_remove_bonded_device
 *
 * Description      BTIF storage API - Deletes the bonded device from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_load_bonded_devices(void);

/*******************************************************************************
 *
 * Function         btif_storage_add_hid_device_info
 *
 * Description      BTIF storage API - Adds the hid information of bonded hid
 *                  devices-to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/

bt_status_t btif_storage_add_hid_device_info(
    bt_bdaddr_t* remote_bd_addr, uint16_t attr_mask, uint8_t sub_class,
    uint8_t app_id, uint16_t vendor_id, uint16_t product_id, uint16_t version,
    uint8_t ctry_code, uint16_t ssr_max_latency, uint16_t ssr_min_tout,
    uint16_t dl_len, uint8_t* dsc_list);

/*******************************************************************************
 *
 * Function         btif_storage_load_bonded_hid_info
 *
 * Description      BTIF storage API - Loads hid info for all the bonded devices
 *                  from NVRAM and adds those devices  to the BTA_HH.
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_load_bonded_hid_info(void);

/*******************************************************************************
 *
 * Function         btif_storage_remove_hid_info
 *
 * Description      BTIF storage API - Deletes the bonded hid device info from
 *                  NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_hid_info(bt_bdaddr_t* remote_bd_addr);

/*******************************************************************************
 *
 * Function         btif_storage_is_retricted_device
 *
 * Description      BTIF storage API - checks if this device is a restricted
 *                  device
 *
 * Returns          true  if the device is labled as restricted
 *                  false otherwise
 *
 ******************************************************************************/
bool btif_storage_is_restricted_device(const bt_bdaddr_t* remote_bd_addr);

bt_status_t btif_storage_add_ble_bonding_key(bt_bdaddr_t* remote_bd_addr,
                                             char* key, uint8_t key_type,
                                             uint8_t key_length);
bt_status_t btif_storage_get_ble_bonding_key(bt_bdaddr_t* remote_bd_addr,
                                             uint8_t key_type, char* key_value,
                                             int key_length);

bt_status_t btif_storage_add_ble_local_key(char* key, uint8_t key_type,
                                           uint8_t key_length);
bt_status_t btif_storage_remove_ble_bonding_keys(bt_bdaddr_t* remote_bd_addr);
bt_status_t btif_storage_remove_ble_local_keys(void);
bt_status_t btif_storage_get_ble_local_key(uint8_t key_type, char* key_value,
                                           int key_len);

bt_status_t btif_storage_get_remote_addr_type(bt_bdaddr_t* remote_bd_addr,
                                              int* addr_type);

bt_status_t btif_storage_set_remote_addr_type(bt_bdaddr_t* remote_bd_addr,
                                              uint8_t addr_type);

/******************************************************************************
 * Exported for unit tests
 *****************************************************************************/
size_t btif_split_uuids_string(const char* str, bt_uuid_t* p_uuid,
                               size_t max_uuids);

#endif /* BTIF_STORAGE_H */

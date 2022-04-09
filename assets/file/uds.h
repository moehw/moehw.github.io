enum UDS_sid {
    DiagnosticSessionControl                 = 0x10,
    ECUReset                                 = 0x11,
    ClearDiagnosticInformation               = 0x14,
    ReadDTCInformation                       = 0x19,
    ReadDataByIdentifier                     = 0x22,
    ReadMemoryByAddress                      = 0x23,
    ReadScalingDataByIdentifier              = 0x24,
    SecurityAccess                           = 0x27,
    CommunicationControl                     = 0x28,
    ReadDataByPeriodicIdentifier             = 0x2A,
    DynamicallyDefineDataIdentifier          = 0x2C,
    WriteDataByIdentifier                    = 0x2E,
    InputOutputControlByIdentifier           = 0x2F,
    RoutineControl                           = 0x31,
    RequestDownload                          = 0x34,
    RequestUpload                            = 0x35,
    TransferData                             = 0x36,
    RequestTransferExit                      = 0x37,
    WriteMemoryByAddress                     = 0x3D,

    TesterPresent                            = 0x3E,

    AccessTimingParameter                    = 0x83,
    SecuredDataTransmission                  = 0x84,
    ControlDTCSetting                        = 0x85,
    ResponseOnEvent                          = 0x86,
    LinkControl                              = 0x87,


    DiagnosticSessionControl_Response        = 0x50,
    ECUReset_Response                        = 0x51,
    ClearDiagnosticInformation_Response      = 0x54,
    ReadDTCInformation_Response              = 0x59,
    ReadDataByIdentifier_Response            = 0x62,

    ReadMemoryByAddress_Response             = 0x63,
    ReadScalingDataByIdentifier_Response     = 0x64,
    SecurityAccess_Response                  = 0x67,
    CommunicationControl_Response            = 0x68,
    ReadDataByPeriodicIdentifier_Response    = 0x6A,
    DynamicallyDefineDataIdentifier_Response = 0x6C,
    WriteDataByIdentifier_Response           = 0x6E,
    InputOutputControlByIdentifier_Response  = 0x6F,
    RoutineControl_Response                  = 0x71,
    RequestDownload_Response                 = 0x74,
    RequestUpload_Response                   = 0x75,
    TransferData_Response                    = 0x76,
    RequestTransferExit_Response             = 0x77,
    WriteMemoryByAddress_Response            = 0x7D,
    Negative_Response                        = 0x7F,

    AccessTimingParameter_Response           = 0xC3,
    SecuredDataTransmission_Response         = 0xC4,
    ControlDTCSetting_Response               = 0xC5,
    ResponseOnEvent_Response                 = 0xC6,
    LinkControl_Response                     = 0xC7,
};                                          

enum UDS_sid_resp {
    positiveResponse                          = 0x00,
    generalReject                             = 0x10,
    serviceNotSupported                       = 0x11,
    subFunctionNotSupported                   = 0x12,
    incorrectMessageLengthOrInvalidFormat     = 0x13,
    busyRepeatRequest                         = 0x21,
    conditionsNotCorrect                      = 0x22,
    requestSequenceError                      = 0x24,
    NoResponseFromSubnetComponent             = 0x25,
    FailurePreventsExecutionOfRequestedAction = 0x26,
    requestOutOfRange                         = 0x31,
    securityAccessDenied                      = 0x33,
    invalidKey                                = 0x35,
    exceedNumberOfAttempts                    = 0x36,
    requiredTimeDelayNotExpired               = 0x37,
    uploadDownloadNotAccepted                 = 0x70,
    transferDataSuspended                     = 0x71,
    generalProgrammingFailure                 = 0x72,
    wrongBlockSequenceCounter                 = 0x73,
    ResponsePending                           = 0x78,
    subFunctionNotSupportedInActiveSession    = 0x7E,
    serviceNotSupportedInActiveSession        = 0x7F,
    rpmTooHigh                                = 0x81,
    rpmTooLow                                 = 0x82,
    engineIsRunning                           = 0x83,
    engineIsNotRunning                        = 0x84,
    engineRunTimeTooLow                       = 0x85,
    temperatureTooHigh                        = 0x86,
    temperatureTooLow                         = 0x87,
    vehicleSpeedTooHigh                       = 0x88,
    vehicleSpeedTooLow                        = 0x89,
    throttle_PedalTooHigh                     = 0x8A,
    throttle_PedalTooLow                      = 0x8B,
    transmissionRangeNotInNeutral             = 0x8C,
    transmissionRangeNotInGear                = 0x8D,
    brakeSwitchNotClosed                      = 0x8F,
    shifterLeverNotInPark                     = 0x90,
    torqueConverterClutchLocked               = 0x91,
    voltageTooHigh                            = 0x92,
    voltageTooLow                             = 0x93,
};

// ISO 14229
enum UDS_did {
    bootSoftwareIdentificationDataIdentifier                  = 0xF180,
    applicationSoftwareIdentificationDataIdentifier           = 0xF181,
    applicationDataIdentificationDataIdentifier               = 0xF182,
    bootSoftwareFingerprintDataIdentifier                     = 0xF183,
    applicationSoftwareFingerprintDataIdentifier              = 0xF184,
    applicationDataFingerprintDataIdentifier                  = 0xF185,
    activeDiagnosticSessionDataIdentifier                     = 0xF186,
    vehicleManufacturerSparePartNumberDataIdentifier          = 0xF187,
    vehicleManufacturerECUSoftwareNumberDataIdentifier        = 0xF188,
    vehicleManufacturerECUSoftwareVersionNumberDataIdentifier = 0xF189,
    systemSupplierIdentifierDataIdentifier                    = 0xF18A,
    ECUManufacturingDateDataIdentifier                        = 0xF18B,
    ECUSerialNumberDataIdentifier                             = 0xF18C,
    supportedFunctionalUnitsDataIdentifier                    = 0xF18D,
    vehicleManufacturerKitAssemblyPartNumberDataIdentifier    = 0xF18E,
    VINDataIdentifier                                         = 0xF190,
    vehicleManufacturerECUHardwareNumberDataIdentifier        = 0xF191,
    systemSupplierECUHardwareNumberDataIdentifier             = 0xF192,
    systemSupplierECUHardwareVersionNumberDataIdentifier      = 0xF193,
    systemSupplierECUSoftwareNumberDataIdentifier             = 0xF194,
    systemSupplierECUSoftwareVersionNumberDataIdentifier      = 0xF195,
    exhaustRegulationOrTypeApprovalNumberDataIdentifier       = 0xF196,
    systemNameOrEngineTypeDataIdentifier                      = 0xF197,
    repairShopCodeOrTesterSerialNumberDataIdentifier          = 0xF198,
    programmingDateDataIdentifier                             = 0xF199,
    calibrationRepairShopCodeOrCalibrationEquipmentSerialNumberData = 0xF19A,
    calibrationDateDataIdentifier                             = 0xF19B,
    calibrationEquipmentSoftwareNumberDataIdentifier          = 0xF19C,
    ECUInstallationDateDataIdentifier                         = 0xF19D,
    ODXFileDataIdentifier                                     = 0xF19E,
    entityDataIdentifier                                      = 0xF19F,
};

struct resp_pos_data_t
{
  UDS_sid sid;
  char sub_func;
  char data;
  char field_3;
  char field_4;
  char field_5;
  char field_6;
  char field_7;
};

struct resp_neg_data_t
{
  char resp;
  UDS_sid sid;
  UDS_sid_resp resp_code;
  char data;
  char field_4;
  char field_5;
  char field_6;
  char field_7;
};

union resp_data_t
{
  resp_pos_data_t pos;
  resp_neg_data_t neg;
};
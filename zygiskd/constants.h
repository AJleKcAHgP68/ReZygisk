#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <android/log.h>

#define bool _Bool
#define true 1
#define false 0

// #define MIN_APATCH_VERSION (atoi(getenv("MIN_APATCH_VERSION")))
// #define MIN_KSU_VERSION (atoi(getenv("MIN_KSU_VERSION")))
// #define MAX_KSU_VERSION (atoi(getenv("MAX_KSU_VERSION")))
// #define MIN_MAGISK_VERSION (atoi(getenv("MIN_MAGISK_VERSION")))
// #define ZKSU_VERSION (getenv("ZKSU_VERSION"))

#define MIN_APATCH_VERSION 0
// val minKsudVersion by extra(11425)
// val maxKsuVersion by extra(20000)
#define MIN_KSU_VERSION 11425
#define MAX_KSU_VERSION 20000
#define MIN_MAGISK_VERSION 0
#define ZKSU_VERSION "1.0.0"

#if DEBUG == false
  #define MAX_LOG_LEVEL ANDROID_LOG_VERBOSE
#else
  #define MAX_LOG_LEVEL ANDROID_LOG_INFO
#endif

#if (defined(__LP64__) || defined(_LP64))
  #define lp_select(a, b) a
#else
  #define lp_select(a, b) b
#endif

#define PATH_MODULES_DIR ".."
#define ZYGOTE_INJECTED (lp_select(5, 4))
#define DAEMON_SET_INFO (lp_select(7, 6))
#define DAEMON_SET_ERROR_INFO (lp_select(9, 8))
#define SYSTEM_SERVER_STARTED 10

enum DaemonSocketAction {
  PingHeartbeat,
  RequestLogcatFd,
  GetProcessFlags,
  GetInfo,
  ReadModules,
  RequestCompanionSocket,
  GetModuleDir,
  ZygoteRestart,
  SystemServerStarted
};

enum ProcessFlags {
  PROCESS_GRANTED_ROOT = 1 << 0,
  PROCESS_ON_DENYLIST = 1 << 1,
  PROCESS_IS_MANAGER = 1 << 28,
  PROCESS_ROOT_IS_APATCH = 1 << 27,
  PROCESS_ROOT_IS_KSU = 1 << 29,
  PROCESS_ROOT_IS_MAGISK = 1 << 30,
  PROCESS_IS_SYSUI = 1 << 31
};

enum RootImplState {
  Supported,
  TooOld,
  Abnormal
};

#endif /* CONSTANTS_H */

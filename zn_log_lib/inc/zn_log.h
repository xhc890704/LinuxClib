/** 
* @file zn_log.h
* @brief ���� linux API ��װ��־��ؽӿ�
* @author zhunian0322@163.com
* @date 19:22 2017/10/31
* @version 1
*/

#ifndef ZN_LOG_H_
#define ZN_LOG_H_


#include <stdint.h>

/** ��־������ */
struct zn_log_configs;
typedef struct zn_log_configs zn_log_config;

/** ��־�ȼ� */
typedef enum {
	ZLL_CUSTOM, 	/**< �Զ��弶�𣬽���־�����Զ����� */
	ZLL_DEBUG, 		/**< ���Լ��� */
	ZLL_WARNIG, 	/**< ���� */
	ZLL_ERROR			/**< ���� */
} ZN_LOG_LEVEL;

/** ��־�����ʶ */
typedef enum {
	ZLSF_NOT, 		/**< �����������浽�ļ�Ҳ��������ն� */
	ZLSF_PRINT, 	/**< ������ն� */
	ZLSF_FLASH, 	/**< ���浽�ļ�*/
	ZLSF_FULL			/**< ��������ն�Ҳ���浽�ļ� */
} ZN_LOG_SAVE_FLAG;

/** 
 *  @breif	�� DEBUG �����ӡ��־  
 *  @param[in] zlc  zn_log_config �ṹ�壬��־������  
 *  @param[in] format ��־����
 */
#define ZNLOG_DEBUG(zlc,format, ...) zn_log(__FILE__,__LINE__,zlc,ZLL_DEBUG,NULL,format, ##__VA_ARGS__)

/** 
 *  @breif	�� WARNIG �����ӡ��־  
 *  @param[in] zlc  zn_log_config �ṹ�壬��־������  
 *  @param[in] format ��־����
 */
#define ZNLOG_WARNIG(zlc,format, ...) zn_log(__FILE__,__LINE__,zlc,ZLL_WARNIG,NULL,format, ##__VA_ARGS__)

/** 
 *  @breif	�� ERROR �����ӡ��־  
 *  @param[in] zlc  zn_log_config �ṹ�壬��־������  
 *  @param[in] format ��־����
 */
#define ZNLOG_ERROR(zlc,format, ...) zn_log(__FILE__,__LINE__,zlc,ZLL_ERROR,NULL,format, ##__VA_ARGS__)

/** 
 *  @breif	�� CUSTOM �����ӡ��־  
 *  @param[in] zlc  zn_log_config �ṹ�壬��־������  
 *  @param[in] tag  ��־��ǩ����ͬ����־�����ǩ
 *  @param[in] format ��־����
 */
#define ZNLOG_CUSTOM(zlc,tag,format, ...) zn_log(__FILE__,__LINE__,zlc,ZLL_CUSTOM,tag,format, ##__VA_ARGS__)

/** 
 *  @breif	��־API��ʼ��  
 *  @param[in] fileName  �������־������������Ҫ����Ϊ��־���Խ��ò�����Ϊ NULL  
 *  @param[in] saveFlag  �����־���ο�  ��־�����ʶ  ZN_LOG_SAVE_FLAG
 *  @param[in] logBufSize ��־���������Χ
 *  @return  �ɹ�����һ����־������ṹ��ָ�룬ʧ�ܷ���NULL
 */
zn_log_config * zn_log_init(uint8_t *fileName, ZN_LOG_SAVE_FLAG saveFlag,
        uint16_t logBufSize);

/** 
 *  @breif	��־������  
 *  @param[in] fileName  ������־���ļ���  
 *  @param[in] line  		 ������־������
 *  @param[in] zlc 			 ��־������� zn_log_init ����
 *  @param[in] level		 ��־����, �ο� ��־�ȼ� ZN_LOG_LEVEL
 *  @param[in] tag			 ��־��ǩ������־�ȼ�Ϊ�Զ���ʱ�����ã�������־�ȼ�ʱ���ò�����Ϊ NULL ����
 *  @param[in] format    ��־����
 *  @note  ������ʹ�øú�������Ҫ��־���ܣ�ʹ����־��ӡ�꼴��
 */
void zn_log(char *filename, int line, zn_log_config * zlc, uint8_t level,
        const uint8_t *tag, char *format, ...);

/** 
 *  @breif	��־������API���� 
 *  @param[in] logConfig  ��־������
 */
void zn_log_destory(zn_log_config ** logConfig);

#endif /* ZN_LOG_H_ */

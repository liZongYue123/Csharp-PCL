#pragma once

#include "pcl_util.h"
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>//ŷʽ����
#include <pcl/ModelCoefficients.h>
#include <pcl/common/transforms.h>
#include <pcl/common/common.h>
#include <pcl/common/common_headers.h>
#include <set>

/*
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,���һ���Բ���
 */

using namespace std;
//���嵼����ʽ����C���Եķ�ʽ��������ΪC���Է�ʽ���������ֲ���
#define EXTERNC extern "C"
//����dll������ʽ���˴��ǵ���������ǵ�����Ϊdllinport
#define HEAD EXTERNC __declspec(dllexport)
//�������Լ�����˴�ѡ���׼����Լ����Ҳ������c����Լ��
#define CallingConvention __stdcall





/*
���ܣ�ʹ��Ransac�㷨��Ϸָ����Ƶ�ƽ�棬������ƽ����б�Ƕ�
param[in] in_pc Ŀ����ƶ���ָ��
param[in] distance_thresh Ransac�㷨������ֵ
param[in] max_itera Ransac�㷨����������
param[out] normal ���ƽ��ķ���ϵ�������ΰ���a��b��c��d�ĸ�ֵ��������ʽΪax+by+cz+d=0
*/
HEAD float CallingConvention fitPlane(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	                                  float distance_thresh, int max_itera, float * normal);
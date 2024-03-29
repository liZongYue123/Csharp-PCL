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

/**
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,utilģ�飬���������ƴ���Ĺ��ߺ���
 */

using namespace std;
//���嵼����ʽ����C���Եķ�ʽ��������ΪC���Է�ʽ���������ֲ���
#define EXTERNC extern "C"
//����dll������ʽ���˴��ǵ���������ǵ�����Ϊdllinport
#define HEAD EXTERNC __declspec(dllexport)
//�������Լ�����˴�ѡ���׼����Լ����Ҳ������c����Լ��
#define CallingConvention __stdcall





/*
���ܣ�����б�ĵ���ƽ��У����Ҳ���ǽ�����ƽ��任����ˮƽ��ƽ��
param[in] in_x Ŀ����ƶ���ָ��
param[in] normal ������Ƶķ�����
param[out] out_x ������ƶ����ָ��
*/
HEAD void CallingConvention correctPlane(pcl::PointCloud<pcl::PointXYZ> * in_pc, float * normal,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);


/*
���ܣ�sigam�����޳��쳣ֵ
param[in] in_pc Ŀ����ƶ���ָ��
param[in] sigam_thresh   sigam������ֵ��һ��Ϊ3
param[out] out_x ������ƶ���ָ��
*/
HEAD void CallingConvention sigamFilter(pcl::PointCloud<pcl::PointXYZ> * in_pc, int sigam_thresh,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ������ư����з���洢��ÿһ�д���һ������Բ�ܣ�������û�ָ����n�в���Բ�ܵ���
param[in] in_pc Ŀ����ƶ���ָ��
param[in] num   ָ����������в���Բ�ܵ��ƣ�һ����˵��nԽ��Խ�ƽ�����ȫ����
��nΪ�������Ƶ�����Ŀ������ľ����������ƣ������Ľ��ʵ�����Ƕ���ȫ������nһ��Ĭ��Ϊ20
param[out] out_x ������ƶ���ָ��
*/
HEAD void CallingConvention getRunoutPoints(pcl::PointCloud<pcl::PointXYZ> * in_pc, int num,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ������Լ����ԣ�ֱ�ӷ��ض���������������ṩ�ӿ�
�����ư����з���洢��ÿһ�д���һ������Բ�ܣ�������û�ָ����n�в���Բ�ܵ���
//���һ����������귨���޳��쳣ֵ�����������յĶ�������
param[in] in_x Ŀ�����x����
param[in] in_y Ŀ�����y����
param[in] in_z Ŀ�����z����
param[in] num   ָ����������в���Բ�ܵ��ƣ�һ����˵��nԽ��Խ�ƽ�����ȫ����
��nΪ�������Ƶ�����Ŀ������ľ����������ƣ������Ľ��ʵ�����Ƕ���ȫ������nһ��Ĭ��Ϊ20
param[out] out_x ������Ƶ�X����
param[out] out_y ������Ƶ�Y����
param[out] out_z ������Ƶ�Z����
*/
HEAD float CallingConvention getRunoutPointsWithResult(pcl::PointCloud<pcl::PointXYZ> * in_pc, int num,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);

/*
���ܣ� �����������,�����ظõ�������С���������
param[in] in_pc Ŀ����ƶ���ָ��
*/
HEAD double CallingConvention calculateRunout(pcl::PointCloud<pcl::PointXYZ> * in_pc, int * indices);

/*
���ܣ� ���ݵ�����������һ�����ƶ����п���������Ӧ�ĵ�
*/
HEAD void CallingConvention copyPcBaseOnIndice(pcl::PointCloud<pcl::PointXYZ> * in_pc,
	pcl::PointIndices * in_indice,
	pcl::PointCloud<pcl::PointXYZ> * out_pc);
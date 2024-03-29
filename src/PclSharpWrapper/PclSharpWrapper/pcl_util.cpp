#include "pcl_util.h"


/*
 * Copyright (c) 2024, ������
 * All rights reserved.
 * Auther:������(lzy)
 * Email:lizyforver@outlook.com
 * 20240307,���ƴ���Ĺ��ߺ������ṩ����ӿ�
 */

//�����������������������ĵ�ص���������
int getMaxPointCluster(vector<pcl::PointIndices> cluster)
{
	int i = 0;
	int pos = 0;
	int max = 0;
	//�����������������е�Ԫ�أ����籾���еĵ�����it�ʹ���һ��pcl::pointindices
	for (vector<pcl::PointIndices>::iterator it = cluster.begin(); it != cluster.end(); ++it)
	{
		if (it->indices.size() > max)
		{
			pos = i;
			max = it->indices.size();
		}
		i = i + 1;
	}
	return pos;
}
//����ƽ������л����Ϻ��ƽ����xy�ο������б��
double getAngle(double line1[3], double line2[3])
{
	double cos = abs(line1[0] * line2[0] + line1[1] * line2[1] + line1[2] * line2[2]) /
		sqrt(line1[0] * line1[0] + line1[1] * line1[1] + line1[2] * line1[2]) * sqrt(line2[0] * line2[0] + line2[1] * line2[1] + line2[2] * line2[2]);
	double deg = std::acos(cos);

	return deg * 180 / 3.1415926;
}
//���ڻ�ȡ�������ı���ת������
Eigen::Matrix4f getRotationMatrix(Eigen::Vector3f vector_before, Eigen::Vector3f vector_after)
{
	vector_before.normalize();
	vector_after.normalize();
	float angle = acos(vector_before.dot(vector_after));//������õ��������ļн�
	Eigen::Vector3f p_rotate = vector_before.cross(vector_after);//������õ��Ļ�������
	p_rotate.normalize();//�������ĵ�λ����������ת��ĵ�λ����
	Eigen::Matrix4f rotationMatrix = Eigen::Matrix4f::Identity();
	rotationMatrix(0, 0) = cos(angle) + p_rotate[0] * p_rotate[0] * (1 - cos(angle));
	rotationMatrix(0, 1) = p_rotate[0] * p_rotate[1] * (1 - cos(angle) - p_rotate[2] * sin(angle));//�������ʽ�ȶ���һ�����ţ����ǿ�ʵ�������ǶԵġ�
	rotationMatrix(0, 2) = p_rotate[1] * sin(angle) + p_rotate[0] * p_rotate[2] * (1 - cos(angle));

	rotationMatrix(1, 0) = p_rotate[2] * sin(angle) + p_rotate[0] * p_rotate[1] * (1 - cos(angle));
	rotationMatrix(1, 1) = cos(angle) + p_rotate[1] * p_rotate[1] * (1 - cos(angle));
	rotationMatrix(1, 2) = -p_rotate[0] * sin(angle) + p_rotate[1] * p_rotate[2] * (1 - cos(angle));

	rotationMatrix(2, 0) = -p_rotate[1] * sin(angle) + p_rotate[0] * p_rotate[2] * (1 - cos(angle));
	rotationMatrix(2, 1) = p_rotate[0] * sin(angle) + p_rotate[1] * p_rotate[2] * (1 - cos(angle));
	rotationMatrix(2, 2) = cos(angle) + p_rotate[2] * p_rotate[2] * (1 - cos(angle));
	return rotationMatrix;
}
//��������������Ϊ���ƶ���
void connect_pc(vector<pcl::PointCloud<pcl::PointXYZ>>& input_pc1, pcl::PointCloud<pcl::PointXYZ> & out_cloud)
{
	for (int i = 0; i < input_pc1.size(); i++)
	{
		out_cloud = out_cloud + input_pc1[i];
	}
}

//�������أ�3�����귨���޳��쳣ֵ�������ǵ��ƣ�����ǵ�������
void stdDev_filter(vector<pcl::PointCloud<pcl::PointXYZ>>& input_cloud, vector<pcl::PointCloud<pcl::PointXYZ>>& out_cloud)
{
	double mean = 0;
	double stdDev = 0;
	vector<float> vec_z;
	out_cloud.resize(input_cloud.size());
	//������Ƶľ�ֵ�ͱ�׼��
	for (int i = 0; i < input_cloud.size(); i++)
	{
		for (int k = 0; k < input_cloud[i].points.size(); k++)
		{
			vec_z.push_back(input_cloud[i].points[k].z);
		}

	}
	pcl::getMeanStdDev(vec_z, mean, stdDev);
	//��2������׼���޳���
	for (int j = 0; j < input_cloud.size(); j++)
	{
		for (int d = 0; d < input_cloud[j].points.size(); d++)
		{
			//�п��ܻ����ĳ���ߵĵ�ȫ�����޳����������ʱ��õ���û�е�᲻�ᱨ��
			if (fabs(input_cloud[j].points[d].z - mean) < 2 * stdDev)
			{
				out_cloud[j].push_back(input_cloud[j].points[d]);
			}
		}

	}
}

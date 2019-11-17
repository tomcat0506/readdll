using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.IO;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CVR100A_U_DSDK_Demo;

namespace CVR100A_U_DSDK_Demo
{
    public partial class MainWnd : Form
    {
        public MainWnd()
        {
            InitializeComponent();
        }

        private void buttonReadCard_Click(object sender, EventArgs e)
        {
            try
            {
                int iPort, iRetUSB = 0;
                for (iPort = 1001; iPort <= 1016; iPort++)
                {
                    iRetUSB = CVRSDK.CVR_InitComm(iPort);
                    if (iRetUSB == 1)
                    {
                        break;
                    }
                }

                if (iRetUSB == 1)
                {
                    this.labelOpResult.Text = "初始化成功！";
                }
                else
                {
                    this.labelOpResult.Text = "初始化失败！";
                }

                int authenticate = CVRSDK.CVR_Authenticate();
                if (authenticate == 1)
                {
                    int readContent = CVRSDK.CVR_Read_FPContent();
                    if (readContent == 1)
                    {
                        this.labelOpResult.Text = "读卡操作成功！";
                        FillData();
                    }
                    else
                    {
                        this.labelOpResult.Text = "读卡操作失败！";
                    }
                }
                else
                {
                    MessageBox.Show("未放卡或卡片放置不正确");
                }
                CVRSDK.CVR_CloseComm();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }


        public void FillData()
        {
            try
            {
                byte[] imgData = new byte[40960];
                int length = 40960;
                CVRSDK.GetBMPData(ref imgData[0], ref length);
                MemoryStream myStream = new MemoryStream();
                for (int i = 0; i < length;i++ )
                {
                    myStream.WriteByte(imgData[i]);
                }
                Image myImage = Image.FromStream(myStream);
                pictureBoxPhoto.Image = myImage;

                byte[] name = new byte[128];
                length = 128;
                CVRSDK.GetPeopleName(ref name[0], ref length);

                byte[] cnName = new byte[128];
                length = 128;
                CVRSDK.GetPeopleChineseName(ref cnName[0], ref length);

                byte[] number = new byte[128];
                length = 128;
                CVRSDK.GetPeopleIDCode(ref number[0], ref length);

                byte[] peopleNation = new byte[128];
                length = 128;
                CVRSDK.GetPeopleNation(ref peopleNation[0], ref length);

                byte[] peopleNationCode = new byte[128];
                length = 128;
                CVRSDK.GetNationCode(ref peopleNationCode[0], ref length);

                byte[] validtermOfStart = new byte[128];
                length = 128;
                CVRSDK.GetStartDate(ref validtermOfStart[0], ref length);

                byte[] birthday = new byte[128];
                length = 128;
                CVRSDK.GetPeopleBirthday(ref birthday[0], ref length);

                byte[] address = new byte[128];
                length = 128;
                CVRSDK.GetPeopleAddress(ref address[0], ref length);

                byte[] validtermOfEnd = new byte[128];
                length = 128;
                CVRSDK.GetEndDate(ref validtermOfEnd[0], ref length);

                byte[] signdate = new byte[128];
                length = 128;
                CVRSDK.GetDepartment(ref signdate[0], ref length);

                byte[] sex = new byte[128];
                length = 128;
                CVRSDK.GetPeopleSex(ref sex[0], ref length);

                byte[] samid = new byte[128];
                CVRSDK.CVR_GetSAMID(ref samid[0]);

                bool bCivic = true;
                byte[] certType = new byte[32];
                length = 32;
                CVRSDK.GetCertType(ref certType[0], ref length);

                string strType = System.Text.Encoding.ASCII.GetString(certType);
                int nStart = strType.IndexOf("I");
                if (nStart != -1) bCivic = false;

                if (bCivic)
                {
                    labelCnName.Visible = false;
                    labelAddress.Visible = true;
                    labelName.Text = "姓名：" + System.Text.Encoding.GetEncoding("GB2312").GetString(name);
                    labelSex.Text = "性别：" + System.Text.Encoding.GetEncoding("GB2312").GetString(sex).Replace("\0", "").Trim();
                    labelNation.Text = "民族：" + System.Text.Encoding.GetEncoding("GB2312").GetString(peopleNation).Replace("\0", "").Trim();
                    labelNationCode.Text = "民族代码：" + System.Text.Encoding.GetEncoding("GB2312").GetString(peopleNationCode).Replace("\0", "").Trim();
                    labelBirthday.Text = "出生日期：" + System.Text.Encoding.GetEncoding("GB2312").GetString(birthday).Replace("\0", "").Trim();
                    labelIdCardNo.Text = "身份证号：" + System.Text.Encoding.GetEncoding("GB2312").GetString(number).Replace("\0", "").Trim();
                    labelAddress.Text = "地址：" + System.Text.Encoding.GetEncoding("GB2312").GetString(address).Replace("\0", "").Trim();
                    labelDepartment.Text = "签发机关：" + System.Text.Encoding.GetEncoding("GB2312").GetString(signdate).Replace("\0", "").Trim();
                    labelValidDate.Text = "有效期限：" + System.Text.Encoding.GetEncoding("GB2312").GetString(validtermOfStart).Replace("\0", "").Trim() + "-" + System.Text.Encoding.GetEncoding("GB2312").GetString(validtermOfEnd).Replace("\0", "").Trim();
                    labelSamID.Text = "安全模块号：" + System.Text.Encoding.GetEncoding("GB2312").GetString(samid).Replace("\0", "").Trim();
                }
                else
                {
                    labelCnName.Visible = true;
                    labelAddress.Visible = false;
                    labelName.Text = "姓名：" + System.Text.Encoding.GetEncoding("GB2312").GetString(name).Replace("\0", "").Trim();
                    labelCnName.Text = "中文姓名：" + System.Text.Encoding.GetEncoding("GB2312").GetString(cnName).Replace("\0", "").Trim();
                    labelSex.Text = "性别：" + System.Text.Encoding.GetEncoding("GB2312").GetString(sex).Replace("\0", "").Trim();
                    labelNation.Text = "国籍：" + System.Text.Encoding.GetEncoding("GB2312").GetString(peopleNation).Replace("\0", "").Trim();
                    labelNationCode.Text = "国籍代码：" + System.Text.Encoding.GetEncoding("GB2312").GetString(peopleNationCode).Replace("\0", "").Trim();
                    labelBirthday.Text = "出生日期：" + System.Text.Encoding.GetEncoding("GB2312").GetString(birthday).Replace("\0", "").Trim();
                    labelIdCardNo.Text = "证件号码：" + System.Text.Encoding.GetEncoding("GB2312").GetString(number).Replace("\0", "").Trim();
                    labelDepartment.Text = "签发机关：" + System.Text.Encoding.GetEncoding("GB2312").GetString(signdate).Replace("\0", "").Trim();
                    labelValidDate.Text = "有效期限：" + System.Text.Encoding.GetEncoding("GB2312").GetString(validtermOfStart).Replace("\0", "").Trim() + "-" + System.Text.Encoding.GetEncoding("GB2312").GetString(validtermOfEnd).Replace("\0", "").Trim();
                    labelSamID.Text = "安全模块号：" + System.Text.Encoding.GetEncoding("GB2312").GetString(samid).Replace("\0", "").Trim();
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
    }
}

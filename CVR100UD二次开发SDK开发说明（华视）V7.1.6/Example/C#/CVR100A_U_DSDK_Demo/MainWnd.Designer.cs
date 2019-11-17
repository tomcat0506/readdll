namespace CVR100A_U_DSDK_Demo
{
    partial class MainWnd
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainWnd));
            this.labelName = new System.Windows.Forms.Label();
            this.labelSex = new System.Windows.Forms.Label();
            this.labelNation = new System.Windows.Forms.Label();
            this.labelBirthday = new System.Windows.Forms.Label();
            this.labelIdCardNo = new System.Windows.Forms.Label();
            this.labelAddress = new System.Windows.Forms.Label();
            this.labelDepartment = new System.Windows.Forms.Label();
            this.labelValidDate = new System.Windows.Forms.Label();
            this.labelSamID = new System.Windows.Forms.Label();
            this.pictureBoxPhoto = new System.Windows.Forms.PictureBox();
            this.labelCnName = new System.Windows.Forms.Label();
            this.labelNationCode = new System.Windows.Forms.Label();
            this.buttonReadCard = new System.Windows.Forms.Button();
            this.labelOpResult = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPhoto)).BeginInit();
            this.SuspendLayout();
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Location = new System.Drawing.Point(32, 33);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(41, 12);
            this.labelName.TabIndex = 0;
            this.labelName.Text = "姓名：";
            // 
            // labelSex
            // 
            this.labelSex.AutoSize = true;
            this.labelSex.Location = new System.Drawing.Point(32, 77);
            this.labelSex.Name = "labelSex";
            this.labelSex.Size = new System.Drawing.Size(41, 12);
            this.labelSex.TabIndex = 1;
            this.labelSex.Text = "性别：";
            // 
            // labelNation
            // 
            this.labelNation.AutoSize = true;
            this.labelNation.Location = new System.Drawing.Point(113, 77);
            this.labelNation.Name = "labelNation";
            this.labelNation.Size = new System.Drawing.Size(41, 12);
            this.labelNation.TabIndex = 2;
            this.labelNation.Text = "民族：";
            // 
            // labelBirthday
            // 
            this.labelBirthday.AutoSize = true;
            this.labelBirthday.Location = new System.Drawing.Point(32, 124);
            this.labelBirthday.Name = "labelBirthday";
            this.labelBirthday.Size = new System.Drawing.Size(65, 12);
            this.labelBirthday.TabIndex = 3;
            this.labelBirthday.Text = "出生日期：";
            // 
            // labelIdCardNo
            // 
            this.labelIdCardNo.AutoSize = true;
            this.labelIdCardNo.Location = new System.Drawing.Point(32, 173);
            this.labelIdCardNo.Name = "labelIdCardNo";
            this.labelIdCardNo.Size = new System.Drawing.Size(65, 12);
            this.labelIdCardNo.TabIndex = 4;
            this.labelIdCardNo.Text = "身份证号：";
            // 
            // labelAddress
            // 
            this.labelAddress.AutoSize = true;
            this.labelAddress.Location = new System.Drawing.Point(32, 223);
            this.labelAddress.Name = "labelAddress";
            this.labelAddress.Size = new System.Drawing.Size(41, 12);
            this.labelAddress.TabIndex = 5;
            this.labelAddress.Text = "地址：";
            // 
            // labelDepartment
            // 
            this.labelDepartment.AutoSize = true;
            this.labelDepartment.Location = new System.Drawing.Point(32, 280);
            this.labelDepartment.Name = "labelDepartment";
            this.labelDepartment.Size = new System.Drawing.Size(65, 12);
            this.labelDepartment.TabIndex = 6;
            this.labelDepartment.Text = "签发机关：";
            // 
            // labelValidDate
            // 
            this.labelValidDate.AutoSize = true;
            this.labelValidDate.Location = new System.Drawing.Point(32, 342);
            this.labelValidDate.Name = "labelValidDate";
            this.labelValidDate.Size = new System.Drawing.Size(65, 12);
            this.labelValidDate.TabIndex = 7;
            this.labelValidDate.Text = "有效期限：";
            // 
            // labelSamID
            // 
            this.labelSamID.AutoSize = true;
            this.labelSamID.Location = new System.Drawing.Point(32, 399);
            this.labelSamID.Name = "labelSamID";
            this.labelSamID.Size = new System.Drawing.Size(77, 12);
            this.labelSamID.TabIndex = 8;
            this.labelSamID.Text = "安全模块号：";
            // 
            // pictureBoxPhoto
            // 
            this.pictureBoxPhoto.Location = new System.Drawing.Point(381, 12);
            this.pictureBoxPhoto.Name = "pictureBoxPhoto";
            this.pictureBoxPhoto.Size = new System.Drawing.Size(112, 137);
            this.pictureBoxPhoto.TabIndex = 9;
            this.pictureBoxPhoto.TabStop = false;
            // 
            // labelCnName
            // 
            this.labelCnName.AutoSize = true;
            this.labelCnName.Location = new System.Drawing.Point(180, 33);
            this.labelCnName.Name = "labelCnName";
            this.labelCnName.Size = new System.Drawing.Size(65, 12);
            this.labelCnName.TabIndex = 10;
            this.labelCnName.Text = "中文姓名：";
            this.labelCnName.Visible = false;
            // 
            // labelNationCode
            // 
            this.labelNationCode.AutoSize = true;
            this.labelNationCode.Location = new System.Drawing.Point(263, 77);
            this.labelNationCode.Name = "labelNationCode";
            this.labelNationCode.Size = new System.Drawing.Size(65, 12);
            this.labelNationCode.TabIndex = 11;
            this.labelNationCode.Text = "民族代码：";
            // 
            // buttonReadCard
            // 
            this.buttonReadCard.Location = new System.Drawing.Point(418, 416);
            this.buttonReadCard.Name = "buttonReadCard";
            this.buttonReadCard.Size = new System.Drawing.Size(75, 23);
            this.buttonReadCard.TabIndex = 12;
            this.buttonReadCard.Text = "读卡";
            this.buttonReadCard.UseVisualStyleBackColor = true;
            this.buttonReadCard.Click += new System.EventHandler(this.buttonReadCard_Click);
            // 
            // labelOpResult
            // 
            this.labelOpResult.AutoSize = true;
            this.labelOpResult.Location = new System.Drawing.Point(32, 460);
            this.labelOpResult.Name = "labelOpResult";
            this.labelOpResult.Size = new System.Drawing.Size(65, 12);
            this.labelOpResult.TabIndex = 13;
            this.labelOpResult.Text = "操作结果：";
            // 
            // MainWnd
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 494);
            this.Controls.Add(this.labelOpResult);
            this.Controls.Add(this.buttonReadCard);
            this.Controls.Add(this.labelNationCode);
            this.Controls.Add(this.labelCnName);
            this.Controls.Add(this.pictureBoxPhoto);
            this.Controls.Add(this.labelSamID);
            this.Controls.Add(this.labelValidDate);
            this.Controls.Add(this.labelDepartment);
            this.Controls.Add(this.labelAddress);
            this.Controls.Add(this.labelIdCardNo);
            this.Controls.Add(this.labelBirthday);
            this.Controls.Add(this.labelNation);
            this.Controls.Add(this.labelSex);
            this.Controls.Add(this.labelName);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "MainWnd";
            this.Text = "深圳华视电子身份证阅读测试程序V3.3.0.6";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPhoto)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Label labelSex;
        private System.Windows.Forms.Label labelNation;
        private System.Windows.Forms.Label labelBirthday;
        private System.Windows.Forms.Label labelIdCardNo;
        private System.Windows.Forms.Label labelAddress;
        private System.Windows.Forms.Label labelDepartment;
        private System.Windows.Forms.Label labelValidDate;
        private System.Windows.Forms.Label labelSamID;
        private System.Windows.Forms.PictureBox pictureBoxPhoto;
        private System.Windows.Forms.Label labelCnName;
        private System.Windows.Forms.Label labelNationCode;
        private System.Windows.Forms.Button buttonReadCard;
        private System.Windows.Forms.Label labelOpResult;
    }
}


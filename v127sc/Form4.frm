VERSION 5.00
Begin VB.Form Form4 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "����"
   ClientHeight    =   3962
   ClientLeft      =   42
   ClientTop       =   378
   ClientWidth     =   4256
   Icon            =   "Form4.frx":0000
   LinkTopic       =   "Form4"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3962
   ScaleWidth      =   4256
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command1 
      Caption         =   "ȷ��"
      Height          =   518
      Left            =   3150
      TabIndex        =   6
      Top             =   882
      Width           =   896
   End
   Begin VB.TextBox Text3 
      Height          =   392
      Left            =   2142
      TabIndex        =   5
      Top             =   1890
      Width           =   1400
   End
   Begin VB.TextBox Text2 
      Height          =   392
      Left            =   1008
      TabIndex        =   4
      Top             =   1260
      Width           =   1778
   End
   Begin VB.TextBox Text1 
      Height          =   392
      Left            =   1008
      TabIndex        =   3
      Top             =   504
      Width           =   1778
   End
   Begin VB.Label Label6 
      Caption         =   "��5�����ֵ����Сֵ�����ܴ���32767С��-32768����ֵ���ܳ���32766������Χ�ָ�Ĭ��"
      Height          =   392
      Index           =   4
      Left            =   14
      TabIndex        =   13
      Top             =   3528
      Width           =   4172
   End
   Begin VB.Label Label6 
      Caption         =   "��4�����ڿ͹�ԭ��һ�����������ĸ���ֻ��       ��1-20���������������ֻ���һ�����"
      Height          =   392
      Index           =   3
      Left            =   0
      TabIndex        =   12
      Top             =   3150
      Width           =   4046
   End
   Begin VB.Label Label6 
      Caption         =   "��3���������Ϊ��ֵ����Χ�ָ�Ĭ��"
      Height          =   266
      Index           =   2
      Left            =   0
      TabIndex        =   11
      Top             =   2898
      Width           =   3290
   End
   Begin VB.Label Label6 
      Caption         =   "��2�������Сֵ�������ֵ��������������˳��"
      Height          =   266
      Index           =   1
      Left            =   0
      TabIndex        =   10
      Top             =   2646
      Width           =   4172
   End
   Begin VB.Label Label6 
      Caption         =   "��1����֧��С�����룬�������ݽ�������������"
      Height          =   266
      Index           =   0
      Left            =   0
      TabIndex        =   9
      Top             =   2394
      Width           =   4046
   End
   Begin VB.Label Label5 
      Caption         =   "��Сֵ"
      Height          =   392
      Left            =   378
      TabIndex        =   8
      Top             =   630
      Width           =   896
   End
   Begin VB.Label Label4 
      Height          =   1148
      Left            =   0
      TabIndex        =   7
      Top             =   0
      Width           =   4046
   End
   Begin VB.Label Label3 
      Caption         =   "һ��������������"
      Height          =   266
      Left            =   378
      TabIndex        =   2
      Top             =   2016
      Width           =   1778
   End
   Begin VB.Label Label2 
      Caption         =   "���ֵ"
      Height          =   392
      Left            =   378
      TabIndex        =   1
      Top             =   1386
      Width           =   896
   End
   Begin VB.Label Label1 
      Caption         =   "��Сֵ"
      Height          =   392
      Left            =   378
      TabIndex        =   0
      Top             =   630
      Width           =   896
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
If Text1.Text = vbNullString Or Text2.Text = vbNullString Then
m = 1
n = 41
Else
If Int(Text1.Text) > 32767 Or Int(Text2.Text) > 32767 Or Int(Text1.Text) < -32768 Or Int(Text2.Text) < -32768 Or Int(Text1.Text) - Int(Text2.Text) > 32767 Or Int(Text2.Text) - Int(Text1.Text) > 32766 Then
m = 1
n = 41
Else
If Int(Text1.Text) > Int(Text2.Text) Then
Dim z As Integer
z = m
m = n
n = z
Else
m = Int(Text1.Text)
n = Int(Text2.Text)
End If
End If
End If

If Text3.Text = vbNullString Then
y = 1
Else
If Int(Text3.Text) < 0 Or Int(Text3.Text) > 20 Then
y = 1
Else
y = Str(Text3.Text)
End If
End If

Unload Form4
End Sub


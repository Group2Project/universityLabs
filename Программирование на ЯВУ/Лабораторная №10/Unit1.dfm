object Form1: TForm1
  Left = 224
  Top = 142
  Width = 708
  Height = 485
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 681
    Height = 433
    Transparent = True
  end
  object Image2: TImage
    Left = 9
    Top = 208
    Width = 313
    Height = 121
    Transparent = True
  end
  object Button1: TButton
    Left = 8
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 648
    Top = 8
  end
end

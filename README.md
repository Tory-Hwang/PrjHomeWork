# PrjHomeWork

[개요]
원의 반지름 길이와 생성개수를 입력하면 640*480 영역에 랜덤하게 원이 생성되는 MFC 프로그램
- 프로그램명 : PrjHomeWork

[개발환경]
- Visual Studio Community 2019

[주요기능]
- 원의 생성
  - 입력한 원의 반지름과 생성 개수에 해당하는 원을 CImage 클래스를 이용하여 생성 
  - 생성된 원의 테두리 색은 노란색이며 원의 중심에는 "+" 표출
- 저장 및 Viewer
  - 640*480 영역에 그려진 이미지 저장 및 display
  - 저장경로 : _T(".\\save.bmp");

[파일설명]
- UserDef.h        : 사용자 정의 헤드 파일
- PrjHomeWorkDlg.h : 프로젝트 헤드 파일
- PrjHomeWorkDlg.cpp: 프로젝트 소스 파일
- CImageView.h     : 이미지 저장 및 표출 헤드 파일
- CImageView.cpp   : 이ㅣ지 저장 및 표출 소스 파일
  

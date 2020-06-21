
# 2020-1-OSSP2-CarpeDiem-5
OSSP project group

# 프로젝트 명
A-KO Shooting game 

# 게임 규칙
■ 코끼리로 날라오는 봉지와 빨대를 공격해 점수를 얻는 방식이다.
■ 여러 방향에서 날아오는 봉지와 빨대를 코끼리가 물대포로 공격하여 점수를 얻는다. 이때, 장애물은 직선과 ZigZag으로 랜덤으로 날아오고, 공격은 직선으로만 가능하다.
■ 봉지를 공격하면 +100점, 빨대를 공격하면 +200점 획득한다.
■ 각 래밸에 할당된 장애물이 모두 소진되는 경우 다음 레밸로 진행된다. 
■ 레벨업 시 장애물이 날아오는 빈도가 증가한다. 
■ 다음 레벨로 이동할 때, 게임을 멈추지 않고, 레벨업 표시만 하고 게임을 계속 진행한다.
■ 목숨 아이템(연꽃)을 부딪혀 먹으면 목숨이 1개 증가하고 물총으로 맞추면 목숨이 2개 증가한다. 
■ 목숨이 다 소진되면 게임 종료된다. 

Screetshots
=================
Main 
<div>
<img width="500" src="https://user-images.githubusercontent.com/59468208/85220193-901daa00-b3e4-11ea-84d1-50b0a3ccd75e.png">
</div>
Instruction  
<div>
<img width="500" src="https://user-images.githubusercontent.com/59468208/85220404-1b4b6f80-b3e6-11ea-87dc-5beb729bdfdc.png">
</div>
Game Screen 
<div>                                                                                                                        
<img width="500" src="https://user-images.githubusercontent.com/59468208/85220743-2227b180-b3e9-11ea-8b22-88bc514ab788.png">             </div>  
 Victory                                                                                                                        
<div>                                                                                                                        
<img width="500" src="https://user-images.githubusercontent.com/59468208/85220474-b80e0d00-b3e6-11ea-9726-5d43faa8e300.png">             </div>  


Open Source
=================
Link : https://github.com/brandonto/sdl-space-shooter.git <br/>
License : MIT License


Language
=================

C++


OS
=================

Linux 64bit


Libraries
=================

(버전 주의!) SDL2 library

Dependancies: lSDL2, lSDL2_image, lSDL2_ttf, and lSDL2_mixer.


Linux에서 실행 방법
=================

[1] Libraries 설치 (Run the following commands on bash:)

- sudo apt-get update

- apt-cache search libsdl2

- sudo apt-get install libsdl2-dev

- sudo apt-get install libsdl2-image-dev

- sudo apt-get install libsdl2-ttf-dev

- sudo apt-get install libsdl2-mixer-dev

[2] 게임 실행 ( Navigate to the directory where you want the project to be cloned
   and run the following commands: )

- git clone https://github.com/CSID-DGU/2020-1-OSSP2-CarpeDiem-5.git

- make all

- cd bin

- ./SpaceShooter


Developers
=================

- 2018112088 김규리
- 2018112042 송승민
- 2018112011 최수정 


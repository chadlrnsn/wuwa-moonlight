#include "Fly.hpp"

bool Fly::ValidatePtr()
{
    return pawn; 
}

void Fly::Draw()
{
	ImGui::Checkbox("FlyHack", &bEnable);
	ImGui::SameLine();
	ImGui::Hotkey("##FlyHack Key", KeyDataToggleData.kb, &KeyDataToggleData.bSettingKey);

	ImGui::BeginDisabled(!bEnable);
	{
		ImGui::Checkbox("NoClip", &m_bEnableCollision);

		ImGui::Spacing();

		ImGui::Text("Flight Speed");
		ImGui::SliderFloat("## Flight Speed Multiplier", &normalSpeed.Current, normalSpeed.Min, normalSpeed.Max);

		ImGui::Spacing();

		ImGui::Text("Flight Z axis speed");
		ImGui::SliderFloat("## Flight Z axis speed", &speedVectical.Current, speedVectical.Min, speedVectical.Max);

		ImGui::Spacing();
		
		// ImGui::Text("Override Methods:");
		// ImGui::Checkbox("Use Gravity Override", &m_bUseGravityOverride);
		// ImGui::Checkbox("Use Velocity Override", &m_bUseVelocityOverride);
		// ImGui::Checkbox("Use NavMesh Override", &m_bUseNavMeshOverride);
		// ImGui::Checkbox("Test Direct Movement Mode", &m_bTestDirect);


		// TODO: Move Up and Down keys
		// ImGui::Text("Move Up");
		// ImGui::SameLine();
		// ImGui::Hotkey("##Move UP", kbUp, &bUpKey);
		// ImGui::Text("Move Down");
		// ImGui::SameLine();
		// ImGui::Hotkey("##Move Down", kbDown, &bDownKey);
	}
	ImGui::EndDisabled();
}

void Fly::HandleFlightControls()
{
    auto pCharController = player_controller->Character;
    if (!pCharController) 
    {
        LOG_ERROR("!!! NO CHARACTER");
        return;
    }

    auto moveComp = pCharController->CharacterMovement;
    if (!moveComp) 
    {
        LOG_ERROR("!!!");
        return;
    };

    auto pCameraManager = player_controller->PlayerCameraManager;
    
    // using vector for movement
    SDK::FVector Direction(0, 0, 0);
    
    // Getting camera and orientation
    auto camRot = pCameraManager->GetCameraRotation();
    
    // View vector (forward/backward)
    if (GetAsyncKeyState('W')) {
        // using straight method instead FRotationMatrix
        float pitch = camRot.Pitch * 3.14159f / 180.0f;
        float yaw = camRot.Yaw * 3.14159f / 180.0f;
        Direction.X += cosf(yaw) * cosf(pitch);
        Direction.Y += sinf(yaw) * cosf(pitch);
        Direction.Z += sinf(pitch);
        LOG_INFO("W");

    }
    if (GetAsyncKeyState('S')) {
        // Opposite direction
        float pitch = camRot.Pitch * 3.14159f / 180.0f;
        float yaw = camRot.Yaw * 3.14159f / 180.0f;
        Direction.X -= cosf(yaw) * cosf(pitch);
        Direction.Y -= sinf(yaw) * cosf(pitch);
        Direction.Z -= sinf(pitch);
        LOG_INFO("S");

    }
    
    // Direction to the right/left of the camera
    if (GetAsyncKeyState('D')) {
        // To the right of the direction of gaze (perpendicular)
        float yaw = camRot.Yaw * 3.14159f / 180.0f;
        Direction.X -= sinf(yaw);
        Direction.Y += cosf(yaw);
        LOG_INFO("D");

    }
    if (GetAsyncKeyState('A')) {
        // To the left of the direction of gaze (perpendicular)
        float yaw = camRot.Yaw * 3.14159f / 180.0f;
        Direction.X += sinf(yaw);
        Direction.Y -= cosf(yaw);
        LOG_INFO("A");

    }
    
    // Vertical movement
    if (GetAsyncKeyState(VK_SPACE)) {
        Direction.Z += 1.0f;
    }
    if (GetAsyncKeyState(VK_LCONTROL)) {
        Direction.Z -= 1.0f;
    }
    
    // If there is motion, normalize the vector and multiply by the velocity
    float sqrMagnitude = Direction.X * Direction.X + 
                            Direction.Y * Direction.Y + 
                            Direction.Z * Direction.Z;
                            
    if (sqrMagnitude > 0.0f) {
        // Manual vector normalization
        float magnitude = sqrtf(sqrMagnitude);
        Direction.X /= magnitude;
        Direction.Y /= magnitude;
        Direction.Z /= magnitude;
        
        // Multiply by speed
        Direction.X *= normalSpeed.Current;
        Direction.Y *= normalSpeed.Current;
        Direction.Z *= normalSpeed.Current;
        
        // Set the speed directly
        moveComp->Velocity = Direction;
    }
}

void Fly::Run()
{
	HandleKeys();

	if (!bEnable) return;

	if (!ValidatePtr()) return;
		
	// 	// Try to change MovementMode directly if the test mode is enabled
	// 	if (m_bTestDirect && character) {
	// 		auto moveComp = character->CharacterMovement;
	// 		if (moveComp) {
	// 			try {
	// 				if (!m_bOnce) {
	// 					LOG_INFO("Trying to change movement mode directly");
	// 					moveComp->MovementMode = SDK::EMovementMode::MOVE_Flying;
						
	// 					if (m_bEnableCollision) character->SetActorEnableCollision(false);
						
	// 					if (GetAsyncKeyState(VK_SPACE)) moveComp->Velocity.Z = normalSpeed.Current; 
	// 					if (GetAsyncKeyState(VK_LCONTROL)) moveComp->Velocity.Z = -normalSpeed.Current;
						
	// 					m_bOnce = true;
	// 				}
	// 			}
	// 			catch(...) {
	// 				LOG_ERROR("Exception when changing MovementMode in Run");
	// 			}
	// 		}
	// 	} else if (m_bOnce && character) {
	// 		auto moveComp = character->CharacterMovement;
	// 		if (moveComp) {
	// 			try {
	// 				LOG_INFO("Restoring movement mode");
	// 				moveComp->MovementMode = SDK::EMovementMode::MOVE_Walking;
	// 				if (character && !character->GetActorEnableCollision()) character->SetActorEnableCollision(true);
	// 			}
	// 			catch(...) {
	// 				LOG_ERROR("Exception when restoring MovementMode");
	// 			}
	// 			m_bOnce = false;
	// 		}
	// 	}
		
	// 	// The method through gravity-defying
	// 	if (m_bUseGravityOverride && character) {
	// 		auto moveComp = character->CharacterMovement;
	// 		if (moveComp) {
	// 			try {
	// 				// Preserving the original gravity value on the first run
	// 				if (!m_bOnce) {
	// 					m_fOriginalGravityScale = moveComp->GravityScale;
	// 					m_bOnce = true;
                        
    //                     // Disable collision if necessary
    //                     if (m_bEnableCollision) character->SetActorEnableCollision(false);
	// 				}
					
	// 				// Defying gravity
	// 				moveComp->GravityScale = 0.0f;
					
	// 				// Controlling the flight
	// 				HandleFlightControls();
	// 			}
	// 			catch(...) {
	// 				LOG_ERROR("Exception when modifying gravity");
	// 			}
	// 		}
	// 	}
		
	// 	// Method via direct velocity control (velocity)
	// 	if (m_bUseVelocityOverride && character) {
	// 		try {
	// 			// Controlling flight via direct speed setting
				HandleFlightControls();
                
    //             // Disable collision if necessary
    //             if (!m_bOnce) {
    //                 if (m_bEnableCollision) character->SetActorEnableCollision(false);
    //                 m_bOnce = true;
    //             }
	// 		}
	// 		catch(...) {
	// 			LOG_ERROR("Exception in velocity override");
	// 		}
	// 	}
		
	// 	// NavMesh method - an attempt to change the navigation parameters
	// 	if (m_bUseNavMeshOverride && character) {
	// 		auto moveComp = character->CharacterMovement;
	// 		if (moveComp) {
	// 			try {
	// 				if (!m_bOnce) {
	// 					// Save the original data and do the initial setup
	// 					m_fOriginalGravityScale = moveComp->GravityScale;
						
	// 					// Changing navigation options
	// 					moveComp->bCanWalkOffLedgesWhenCrouching = true;
	// 					moveComp->bCanWalkOffLedges = true;
	// 					moveComp->GroundFriction = 0;
	// 					moveComp->BrakingFrictionFactor = 0;
						
	// 					// Set up unrealistically high parameters
	// 					moveComp->JumpZVelocity = speedVectical.Current;
	// 					moveComp->AirControl = 1.0f;
	// 					moveComp->MaxAcceleration = normalSpeed.Current * 10;
						
	// 					if (m_bEnableCollision) character->SetActorEnableCollision(false);
						
	// 					m_bOnce = true;
	// 				}
					
	// 				// Control flight using modified parameters
	// 				moveComp->GravityScale = (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_LCONTROL)) ? 0.0f : 0.01f;
					
	// 				HandleFlightControls();
	// 			}
	// 			catch(...) {
	// 				LOG_ERROR("Exception in NavMesh override");
	// 			}
	// 		}
	// 	}
	// } else {
	// 	// Restore settings if the feature is disabled and bypass methods were active
	// 	if (m_bOnce && character) {
	// 		auto moveComp = character->CharacterMovement;
	// 		if (moveComp) {
	// 			try {
	// 				LOG_INFO("Restoring settings");
					
	// 				// Restore gravity
	// 				moveComp->GravityScale = m_fOriginalGravityScale;
					
	// 				// Restore movement mode just in case
	// 				moveComp->MovementMode = SDK::EMovementMode::MOVE_Walking;
					
	// 				// Restore collision
	// 				if (character && !character->GetActorEnableCollision()) 
	// 					character->SetActorEnableCollision(true);
					
	// 				m_bOnce = false;
	// 			}
	// 			catch(...) {
	// 				LOG_ERROR("Exception when restoring settings");
	// 			}
	// 		}
	// 	}
	// }
}
/*
 * Copyright 2011 Marshmallow Engine. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY MARSHMALLOW ENGINE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MARSHMALLOW ENGINE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Marshmallow Engine.
 */

#include "game.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

MARSHMALLOW_NAMESPACE_USE;

#include <game/viewbase.h>

#include "mainscene.h"
#include "enemyview.h"

Demo::Demo(void)
    : Engine(),
      m_stop_timer(0),
      m_event_manager(new Event::EventManager("main")),
      m_scene_manager(new Game::SceneManager(Game::SharedScene())),
      m_view_manager(new Game::ViewManager())
{
}

void
Demo::initialize(void)
{
	Engine::initialize();

	setEventManager(m_event_manager);
	setSceneManager(m_scene_manager);
	setViewManager(m_view_manager);

	Game::SharedScene l_scene(new MainScene);
	m_scene_manager->push(l_scene);

	/* tmp added here */
	Game::SharedView l_view1(new Game::ViewBase);
	Game::SharedView l_enemy(new EnemyView);
	m_view_manager->addView(l_view1);
	m_view_manager->addView(l_enemy);
}

void
Demo::finalize(void)
{
	Engine::finalize();
}

void
Demo::second(void)
{
	if (++m_stop_timer == 10)
		stop();
}

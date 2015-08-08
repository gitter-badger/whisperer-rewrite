#include "Scene.h"

#include "Point.h"
using namespace ascii;

#include "Whisperer.h"

Scene::Scene()
    : mBackgroundSurface(Whisperer::WINDOW_WIDTH, Whisperer::WINDOW_HEIGHT),
    mShown(false)
{
}

void Scene::BlitBackgroundSurface(Surface* background, int x, int y)
{
    mBackgroundSurface.blitSurface(background, x, y);
}

void Scene::CopyBackgroundSurface(Surface* background, int x, int y)
{
    mBackgroundSurface.copySurface(background, x, y);
}

void Scene::AddBackgroundImage(string key, int x, int y)
{
    mBackgroundImages[key] = Point(x, y);
}

void Scene::AddForegroundImage(string key, int x, int y)
{
    mForegroundImages[key] = Point(x, y);
}

void Scene::ClearImages()
{
    mBackgroundImages.clear();
    mForegroundImages.clear();
}

void Scene::TweenSurface(Surface* surface, int sourceX, int sourceY,
        int destX, int destY, unsigned int totalMS)
{
    mTweens.push_back(Tween(surface, Point(sourceX, sourceY),
                Point(destX, destY), totalMS));
}

void Scene::Update(int deltaMS)
{
    // Update every tween
    for (auto it = mTweens.begin(); it != mTweens.end(); ++it)
    {
        it->Update(deltaMS);
    }

    // TODO update dialog boxes
}

void Scene::Show(Graphics& graphics)
{
    mShown = true;

    for (auto it = mBackgroundImages.begin(); it != mBackgroundImages.end(); ++it)
    {
        graphics.addBackgroundImage(it->first, it->first,
                it->second.x, it->second.y);
    }

    for (auto it = mForegroundImages.begin(); it != mForegroundImages.end(); ++it)
    {
        graphics.addForegroundImage(it->first, it->first,
                it->second.x, it->second.y);
    }
}

void Scene::Draw(Graphics& graphics)
{
    graphics.clear();

    // First, draw the background
    graphics.blitSurface(&mBackgroundSurface, 0, 0);

    // Draw every tweening surface at its current position
    for (auto it = mTweens.begin(); it != mTweens.end(); ++it)
    {
        it->Draw(graphics);
    }

    // TODO draw dialog boxes
}

void Scene::Hide(Graphics& graphics)
{
    mShown = false;

    graphics.clear();

    for (auto it = mBackgroundImages.begin(); it != mBackgroundImages.end(); ++it)
    {
        graphics.removeBackgroundImage(it->first);
    }

    for (auto it = mForegroundImages.begin(); it != mForegroundImages.end(); ++it)
    {
        graphics.removeForegroundImage(it->first);
    }
}

bool Scene::IsFinished()
{
    return this->allTweensFinished(); // && TODO dialogs finished as well
}

bool Scene::DrawEveryFrame()
{
    return !mTweens.empty(); // || TODO dialogs present
}

bool Scene::allTweensFinished()
{
    for (auto it = mTweens.begin(); it != mTweens.end(); ++it)
    {
        if (!it->IsFinished())
        {
            return false;
        }
    }

    return true;
}
